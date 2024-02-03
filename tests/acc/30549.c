#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int max;
} Node;

void buildTree(int* sequence, Node* tree, int start, int end, int index) {
    if (start == end) {
        tree[index].max = sequence[start];
        return;
    }

    int mid = (start + end) / 2;
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    buildTree(sequence, tree, start, mid, leftIndex);
    buildTree(sequence, tree, mid + 1, end, rightIndex);

    tree[index].max = (tree[leftIndex].max > tree[rightIndex].max) ? tree[leftIndex].max : tree[rightIndex].max;
}

int queryTree(Node* tree, int start, int end, int qStart, int qEnd, int index) {
    if (qStart > end || qEnd < start) {
        return INT_MIN;
    }

    if (qStart <= start && qEnd >= end) {
        return tree[index].max;
    }

    int mid = (start + end) / 2;
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    int leftMax = queryTree(tree, start, mid, qStart, qEnd, leftIndex);
    int rightMax = queryTree(tree, mid + 1, end, qStart, qEnd, rightIndex);

    return (leftMax > rightMax) ? leftMax : rightMax;
}

void updateTree(Node* tree, int start, int end, int index, int i, int value) {
    if (i < start || i > end) {
        return;
    }

    if (start == end) {
        tree[index].max = value;
        return;
    }

    int mid = (start + end) / 2;
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    updateTree(tree, start, mid, leftIndex, i, value);
    updateTree(tree, mid + 1, end, rightIndex, i, value);

    tree[index].max = (tree[leftIndex].max > tree[rightIndex].max) ? tree[leftIndex].max : tree[rightIndex].max;
}

int main() {
    int n;
    scanf("%d", &n);

    int* sequence = (int*)malloc(n * sizeof(int));
    if (sequence == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    int treeSize = 4 * n;
    Node* tree = (Node*)malloc(treeSize * sizeof(Node));
    if (tree == NULL) {
        free(sequence);
        return 1;
    }

    buildTree(sequence, tree, 0, n - 1, 0);

    char operation[4];
    memset(operation, 0, sizeof(operation));

    while (strcmp(operation, "END") != 0) {
        scanf("%s", operation);

        if (strcmp(operation, "MAX") == 0) {
            int i, r;
            scanf("%d %d", &i, &r);

            int result = queryTree(tree, 0, n - 1, i, r, 0);
            printf("%d\n", result);
        }
        else if (strcmp(operation, "UPD") == 0) {
            int i, v;
            scanf("%d %d", &i, &v);

            sequence[i] = v;
            updateTree(tree, 0, n - 1, 0, i, v);
        }
    }

    free(sequence);
    free(tree);

    return 0;
}
