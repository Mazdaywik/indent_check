#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct AVLNode {
    char identifier[1000];
    int value;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

struct AVLNode* newNode(char identifier[1000], int value) {
    struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    if (node == NULL) {
        return NULL;
    }
    strncpy(node->identifier, identifier, sizeof(node->identifier) - 1);
    node->identifier[sizeof(node->identifier) - 1] = '\0';
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}


int height(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max_value(int a, int b) {
    return (a > b) ? a : b;
}

int getBalance(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct AVLNode* Rotate_R(struct AVLNode* y) {
    if (y == NULL || y->left == NULL)
        return y;

    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max_value(height(y->left), height(y->right));
    x->height = 1 + max_value(height(x->left), height(x->right));

    return x;
}

struct AVLNode* Rotate_L(struct AVLNode* x) {
    if (x == NULL || x->right == NULL)
        return x;

    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max_value(height(x->left), height(x->right));
    y->height = 1 + max_value(height(y->left), height(y->right));

    return y;
}

struct AVLNode* insert(struct AVLNode* node, char identifier[1000], int value) {
    if (node == NULL)
        return newNode(identifier, value);

    int compareResult = strcmp(identifier, node->identifier);

    if (compareResult < 0)
        node->left = insert(node->left, identifier, value);
    else if (compareResult > 0)
        node->right = insert(node->right, identifier, value);
    else
        return node; 

    node->height = 1 + max_value(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1) {
        if (compareResult < 0)
            return Rotate_R(node);
        else {
            if (node->left != NULL)
                node->left = Rotate_L(node->left);
            return Rotate_R(node);
        }
    }

    if (balance < -1) {
        if (compareResult > 0)
            return Rotate_L(node);
        else {
            if (node->right != NULL) 
                node->right = Rotate_R(node->right);
            return Rotate_L(node);
        }
    }

    return node;
}

int search(struct AVLNode* root, char identifier[1000]) {
    if (root == NULL)
        return -1;

    if (strcmp(identifier, root->identifier) < 0)
        return search(root->left, identifier);
    else if (strcmp(identifier, root->identifier) > 0)
        return search(root->right, identifier);
    else
        return root->value;
}

void freeTree(struct AVLNode* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void lexicalAnalysis(char* sentence, int n) {
    struct AVLNode* root = NULL;
    char sentences[6] = { '+', '-', '*', '/', '(', ')' };
    int identifierCount = 0;

    for (int i = 0; i < n; ++i) {
        if (sentence[i] == ' ') {
            continue;
        }
        else if (isdigit(sentence[i])) {
            int value = 0;
            while (i < n && isdigit(sentence[i])) {
                value = value * 10 + (sentence[i] - '0');
                ++i;
            }
            printf("CONST %d\n", value);
            --i;
        }
        else if (isalpha(sentence[i])) {
            char identifier[1000];
            int j = 0;
            while (i < n && (isalpha(sentence[i]) || isdigit(sentence[i]))) {
                identifier[j++] = sentence[i++];
            }
            identifier[j] = '\0';

            int value = search(root, identifier);
            if (value == -1) {
                value = identifierCount++;
                root = insert(root, identifier, value);
            }

            printf("IDENT %d\n", value);
            --i;
        }
        else {
            for (int j = 0; j < 6; j++)
                if (i < n && sentence[i] == sentences[j])
                    printf("SPEC %d\n", j);
        }
    }

    freeTree(root);
}

int main() {
    int n;
    scanf("%d", &n);

    char* sentence = (char*)malloc((n + 2) * sizeof(char));

    memset(sentence, 0, (n + 2) * sizeof(char));

    scanf(" %[^\n]s", sentence);

    lexicalAnalysis(sentence, n);

    free(sentence);

    return 0;
}