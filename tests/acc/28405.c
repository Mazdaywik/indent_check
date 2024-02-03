#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

struct AVLNode {
    char *identifier;
    int value;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

struct AVLNode *createNode(char *identifier, int value) {
    struct AVLNode *node = (struct AVLNode *)malloc(sizeof(struct AVLNode));
    if (node == NULL) {
        exit(EXIT_FAILURE);
    }
    node->identifier = (char *)malloc(strlen(identifier) + 1);
    if (node->identifier == NULL) {
        free(node);
        exit(EXIT_FAILURE);
    }
    strcpy(node->identifier, identifier);

    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}
int height(struct AVLNode *node) {
    return (node == NULL) ? 0 : node->height;
}

int getBalance(struct AVLNode *node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

void updateHeight(struct AVLNode *node) {
    if (node != NULL) {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

struct AVLNode *rotateRight(struct AVLNode *y) {
    struct AVLNode *x = y->left;
    struct AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

struct AVLNode *rotateLeft(struct AVLNode *x) {
    struct AVLNode *y = x->right;
    struct AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

struct AVLNode *insert(struct AVLNode *root, char identifier[], int *identifierCount) {
    if (root == NULL) {
        (*identifierCount)++;
        return createNode(identifier, *identifierCount - 1);
    }

    int compareResult = strcmp(identifier, root->identifier);

    if (compareResult < 0)
        root->left = insert(root->left, identifier, identifierCount);
    else if (compareResult > 0)
        root->right = insert(root->right, identifier, identifierCount);
    else
        return root;

    updateHeight(root);

    int balance = getBalance(root);

    if (balance > 1 && strcmp(identifier, root->left->identifier) < 0)
        return rotateRight(root);

    if (balance < -1 && strcmp(identifier, root->right->identifier) > 0)
        return rotateLeft(root);

    if (balance > 1 && strcmp(identifier, root->left->identifier) > 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && strcmp(identifier, root->right->identifier) < 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

int search(struct AVLNode *root, char identifier[]) {
    if (root == NULL)
        return -1;

    int compareResult = strcmp(identifier, root->identifier);

    if (compareResult == 0)
        return root->value;
    else if (compareResult < 0)
        return search(root->left, identifier);
    else
        return search(root->right, identifier);
}

void freeTree(struct AVLNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        if (root->identifier != NULL) {
            free(root->identifier);
        }
        free(root);
    }
}


void lexicalAnalysis(struct AVLNode **root, int *identifierCount, int n) {
    int c;
    char buffer[n];
    int bufferIndex = 0;

    while ((c = getchar()) != EOF && bufferIndex < n) {
        if (isspace(c) || c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/') {
            if (bufferIndex > 0) {
                buffer[bufferIndex] = '\0';
                if (isdigit(buffer[0])) {
                    char *endptr;
                    errno = 0;
                    long int result = strtol(buffer, &endptr, 10);
                    if (errno == 0 && *endptr == '\0') {
                        printf("CONST %ld\n", result);
                    }
                } else {
                    int idValue = search(*root, buffer);
                    if (idValue == -1) {
                        *root = insert(*root, buffer, identifierCount);
                        printf("IDENT %d\n", search(*root, buffer));
                    } else {
                        printf("IDENT %d\n", idValue);
                    }
                }
                bufferIndex = 0;
            }

            if (isspace(c)) {
                continue;
            }

            if (c == '(')
                printf("SPEC 4\n");
            else if (c == ')')
                printf("SPEC 5\n");
            else if (c == '+')
                printf("SPEC 0\n");
            else if (c == '-')
                printf("SPEC 1\n");
            else if (c == '*')
                printf("SPEC 2\n");
            else if (c == '/')
                printf("SPEC 3\n");
        } else {
            buffer[bufferIndex++] = c;
        }
    }

    if (bufferIndex > 0) {
        buffer[bufferIndex] = '\0';
        if (isdigit(buffer[0])) {
            char *endptr;
            errno = 0;
            long int result = strtol(buffer, &endptr, 10);
            if (errno == 0 && *endptr == '\0') {
                printf("CONST %ld\n", result);
            }
        } else {
            int idValue = search(*root, buffer);
            if (idValue == -1) {
                *root = insert(*root, buffer, identifierCount);
                printf("IDENT %d\n", search(*root, buffer));
            } else {
                printf("IDENT %d\n", idValue);
            }
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return EXIT_FAILURE;
    }

    struct AVLNode *root = NULL;
    int identifierCount = 0;

    lexicalAnalysis(&root, &identifierCount, n);

    if (root != NULL) {
        freeTree(root);
    }

    return 0;
}
