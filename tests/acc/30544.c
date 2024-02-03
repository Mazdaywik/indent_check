#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    int key;
    char value[11];
    int count;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *createNode(int key, const char *value) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->key = key;
    strcpy(node->value, value);
    node->count = 1;
    node->left = node->right = NULL;
    return node;
}

void updateCount(TreeNode *node) {
    if (node == NULL) return;
    node->count = 1;
    if (node->left != NULL) node->count += node->left->count;
    if (node->right != NULL) node->count += node->right->count;
}

TreeNode *insert(TreeNode *node, int key, const char *value) {
    if (node == NULL) return createNode(key, value);

    if (key < node->key)
        node->left = insert(node->left, key, value);
    else if (key > node->key)
        node->right = insert(node->right, key, value);
    
    updateCount(node);
    return node;
}

TreeNode *search(TreeNode *node, int key) {
    if (node == NULL || node->key == key)
        return node;

    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode *minValueNode(TreeNode *node) {
    TreeNode *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            TreeNode *temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        } else {
            TreeNode *temp = minValueNode(root->right);
            root->key = temp->key;
            strcpy(root->value, temp->value);
            root->right = deleteNode(root->right, temp->key);
        }
    }

    updateCount(root);
    return root;
}


void freeTree(TreeNode *node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

TreeNode *searchByRank(TreeNode *root, int rank) {
    if (root == NULL) return NULL;

    int leftSize = root->left == NULL ? 0 : root->left->count;

    if (leftSize + 1 == rank) 
        return root;
    else if (rank <= leftSize) 
        return searchByRank(root->left, rank);
    else 
        return searchByRank(root->right, rank - leftSize - 1);
}

int main() {
    TreeNode *root = NULL;
    char operation[10];
    int key, rank;
    char value[11];

    while (scanf("%s", operation) != EOF) {
        if (strcmp(operation, "INSERT") == 0) {
            scanf("%d %s", &key, value);
            root = insert(root, key, value);
        } else if (strcmp(operation, "LOOKUP") == 0) {
            scanf("%d", &key);
            TreeNode *res = search(root, key);
            if (res != NULL) printf("%s\n", res->value);
        } else if (strcmp(operation, "DELETE") == 0) {
            scanf("%d", &key);
            root = deleteNode(root, key);
        } else if (strcmp(operation, "SEARCH") == 0) {
            scanf("%d", &rank);
            TreeNode *res = searchByRank(root, rank + 1); // +1 because rank is 0-indexed
            if (res != NULL) printf("%s\n", res->value);
        } else if (strcmp(operation, "END") == 0) {
            break;
        }
    }

    freeTree(root);

    return 0;
}
