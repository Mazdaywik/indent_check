#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLNode {
    char* key;
    int value;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(AVLNode* node) {
    if (node == NULL) 
        return 0;
    return node->height;
}

AVLNode* createNode(char* key, int value) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    newNode->key = key;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getBalance(AVLNode* node) {
    if (node == NULL) 
        return 0;
    return height(node->left) - height(node->right);
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode* insert(AVLNode* node, char* key, int value) {
    if (node == NULL) return createNode(key, value);

    if (strcmp(key, node->key) < 0) {
        node->left = insert(node->left, key, value);
    } else if (strcmp(key, node->key) > 0) {
        node->right = insert(node->right, key, value);
    } else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && strcmp(key, node->left->key) < 0) {
        return rotateRight(node);
    }

    if (balance < -1 && strcmp(key, node->right->key) > 0) {
        return rotateLeft(node);
    }

    if (balance > 1 && strcmp(key, node->left->key) > 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && strcmp(key, node->right->key) < 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

int search(AVLNode* root, char* key) {
    if (root == NULL || root->key == NULL) 
        return -1;
    if (strcmp(key, root->key) == 0) 
        return root->value;
    if (strcmp(key, root->key) < 0) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int isConst(char c) {
    return (c >= '0') && (c <= '9');
}

int isSpec(char c) {
    char* str = "+-*/()";
    for (int i = 0; i < 6; i++)
        if (str[i] == c) return i;
    return -1;
}

int isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void freeAVLTree(AVLNode* node) {
    if (node == NULL) return;
    freeAVLTree(node->left);
    freeAVLTree(node->right);
    free(node->key);
    free(node);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int star_char;
    AVLNode* root = NULL;
    int count_ident = 0;
    star_char = getchar();
    int p = 1;
    for (int i = 0; i < n; i++) {
        if (p)
            star_char = getchar();
        if (star_char == ' ') {
            p = 1;
        } else if (isSpec(star_char) >= 0) {
            p = 1;
            printf("SPEC %d\n", isSpec(star_char));
        } else if (isConst(star_char)) {
            long long number = 0;
            while (isConst(star_char) && i < n) {
                number = number * 10 + (star_char - '0');
                i++;
                star_char = getchar();
            }
            printf("CONST %lld\n", number);
            p = 0;
            i--;
        } else if (isLetter(star_char)) {
            char *identifier = (char *)malloc(1000* sizeof(char));
            int k = 0;
            while ((isConst(star_char) || isLetter(star_char)) && i < n) {
                identifier[k++] = star_char;
                i++;
                star_char = getchar();
            }
            identifier[k] = '\0';
            int value = search(root, identifier);
            if (value == -1) {
                root = insert(root, identifier, count_ident);
                printf("IDENT %d\n", count_ident);
                count_ident++;
            } else {
                printf("IDENT %d\n", value);
                free(identifier);
            }
            p = 0;
            i--;
        }
    }
    freeAVLTree(root);
    return 0;
}