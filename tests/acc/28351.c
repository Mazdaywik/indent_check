#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int key;
    char value[10];
    int count;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key, const char* value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    strncpy(newNode->value, value, sizeof(newNode->value) - 1);
    newNode->value[sizeof(newNode->value) - 1] = '\0';
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void updateCount(struct Node* root) {
    if (root != NULL) {
        root->count = 1;
        if (root->left != NULL) {
            root->count += root->left->count;
        }
        if (root->right != NULL) {
            root->count += root->right->count;
        }
    }
}

struct Node* insert(struct Node* root, int key, const char* value) {
    if (root == NULL) {
        return createNode(key, value);
    }

    if (key < root->key) {
        root->left = insert(root->left, key, value);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key, value);
    }

    updateCount(root);

    return root;
}

struct Node* searchByRank(struct Node* root, int rank) {
    if (root == NULL) {
        return NULL;
    }

    int leftCount = (root->left != NULL) ? root->left->count : 0;

    if (rank == leftCount) {
        return root;
    }
    else if (rank < leftCount) {
        return searchByRank(root->left, rank);
    }
    else {
        return searchByRank(root->right, rank - leftCount - 1);
    }
}

struct Node* searchByKey(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return searchByKey(root->left, key);
    }
    else {
        return searchByKey(root->right, key);
    }
}

struct Node* deleteMin(struct Node* root) {
    if (root->left == NULL) {
        struct Node* rightChild = root->right;
        free(root);
        return rightChild;
    }

    root->left = deleteMin(root->left);
    updateCount(root);

    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            struct Node* rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            struct Node* leftChild = root->left;
            free(root);
            return leftChild;
        }
        else {
            struct Node* minRight = searchByRank(root->right, 0);
            root->key = minRight->key;
            strncpy(root->value, minRight->value, sizeof(root->value) - 1);
            root->value[sizeof(root->value) - 1] = '\0';
            root->right = deleteMin(root->right);
        }
    }

    updateCount(root);

    return root;
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;

    char operation[10];
    int key;
    char value[10];

    while (1) {
        scanf("%s", operation);

        if (strcmp(operation, "END") == 0) {
            break;
        }
        else if (strcmp(operation, "INSERT") == 0) {
            scanf("%d %s", &key, value);
            root = insert(root, key, value);
        }
        else if (strcmp(operation, "LOOKUP") == 0) {
            scanf("%d", &key);
            struct Node* result = searchByKey(root, key);
            if (result != NULL) {
                printf("%s\n", result->value);
            }
            else {
                printf("Key not found\n");
            }
        }
        else if (strcmp(operation, "SEARCH") == 0) {
            int rank;
            scanf("%d", &rank);
            struct Node* result = searchByRank(root, rank);
            if (result != NULL) {
                printf("%s\n", result->value);
            }
            else {
                printf("Rank not found\n");
            }
        }
        else if (strcmp(operation, "DELETE") == 0) {
            scanf("%d", &key);
            root = deleteNode(root, key);
        }
    }

    freeTree(root);

    return 0;
}