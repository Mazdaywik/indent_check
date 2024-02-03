#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALUE_SIZE 10

typedef struct TreeNode {
    long key;
    char value[VALUE_SIZE];
    long count;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(long key, const char *value) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    strncpy(node->value, value, VALUE_SIZE - 1);
    node->value[VALUE_SIZE - 1] = '\0';
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

long treeSize(TreeNode *root) {
    return root ? root->count : 0;
}

void updateCount(TreeNode *root) {
    if (root != NULL) {
        root->count = 1 + treeSize(root->left) + treeSize(root->right);
    }
}

TreeNode *rotateRight(TreeNode *y) {
    if (y == NULL || y->left == NULL) {
        return y;
    }
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateCount(y);
    updateCount(x);

    return x;
}

TreeNode *rotateLeft(TreeNode *x) {
    if (x == NULL || x->right == NULL) {
        return x;
    }
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    updateCount(x);
    updateCount(y);
    return y;
}

TreeNode *insert(TreeNode *root, long key, const char *value) {
    if (root == NULL) {
        return createNode(key, value);
    }

    if (key < root->key) {
        root->left = insert(root->left, key, value);
    } else if (key > root->key) {
        root->right = insert(root->right, key, value);
    } else {
        strncpy(root->value, value, VALUE_SIZE - 1);
        root->value[VALUE_SIZE - 1] = '\0';  
        return root;
    }

    updateCount(root);

    long balance = treeSize(root->left) - treeSize(root->right);
    if (balance > 1) {
        if (key < root->left->key) {
            return rotateRight(root);
        } else {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if (balance < -1) {
        if (key > root->right->key) {
            return rotateLeft(root);
        } else {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

TreeNode *searchByRank(TreeNode *root, long rank) {
    if (root == NULL) {
        return NULL;
    }

    long rootRank = treeSize(root->left);

    if (rank == rootRank) {
        return root;
    } else if (rank < rootRank) {
        return searchByRank(root->left, rank);
    } else {
        return searchByRank(root->right, rank - (rootRank + 1));
    }
}

TreeNode *search(TreeNode *root, long key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void inorderTraversal(TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("(%ld, %s) ", root->key, root->value);
        inorderTraversal(root->right);
    }
}

void freeTree(TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

TreeNode *lookup(TreeNode *root, long key) {
    TreeNode *result = search(root, key);
    return result;
}

TreeNode *minValueNode(TreeNode *node) {
    TreeNode *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

TreeNode *deleteNode(TreeNode *root, long key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        TreeNode *temp = minValueNode(root->right);
        root->key = temp->key;
        strncpy(root->value, temp->value, VALUE_SIZE - 1);
        root->value[VALUE_SIZE - 1] = '\0';  
        root->right = deleteNode(root->right, temp->key);
    }

    updateCount(root);

    long balance = treeSize(root->left) - treeSize(root->right);

    if (balance > 1) {
        if (treeSize(root->left->right) > treeSize(root->left->left)) {
            root->left = rotateLeft(root->left);
        }
        return rotateRight(root);
    }
    if (balance < -1) {
        if (treeSize(root->right->left) > treeSize(root->right->right)) {
            root->right = rotateRight(root->right);
        }
        return rotateLeft(root);
    }

    return root;
}

int main() {
    TreeNode *root = NULL;

    long key;
    char value[VALUE_SIZE];
    long rank;

    while (1) {
        char operation[10];
        scanf("%s", operation);

        if (operation[0] == 'I') {
            scanf("%ld %s", &key, value);
            root = insert(root, key, value);
        } else if (operation[0] == 'L') {
            scanf("%ld", &key);
            TreeNode *result = lookup(root, key);
            if (result != NULL) {
                printf("%s\n", result->value);
            }
        } else if (operation[0] == 'S') {
            scanf("%ld", &rank);
            TreeNode *result = searchByRank(root, rank);
            if (result != NULL) {
                printf("%s\n", result->value);
            }
        } else if (operation[0] == 'D') {
            scanf("%ld", &key);
            root = deleteNode(root, key);
        } else if (operation[0] == 'E') {
            break;
        }
    }

    freeTree(root);

    return 0;
}
