#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int buildSegmentTree(int arr[], int tree[], int start, int end, int treeNode) {
    if (start == end) {
        tree[treeNode] = arr[start];
        return arr[start];
    }

    int mid = (start + end) / 2;
    int leftMax = buildSegmentTree(arr, tree, start, mid, 2 * treeNode);
    int rightMax = buildSegmentTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    tree[treeNode] = (leftMax > rightMax) ? leftMax : rightMax;
    return tree[treeNode];
}

int query(int tree[], int start, int end, int treeNode, int left, int right) {

    if (start > right || end < left) {
        return INT_MIN;
    }

    if (start >= left && end <= right) {
        return tree[treeNode];
    }

    int mid = (start + end) / 2;
    int leftMax = query(tree, start, mid, 2 * treeNode, left, right);
    int rightMax = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);

    return (leftMax > rightMax) ? leftMax : rightMax;
}

void update(int tree[], int start, int end, int treeNode, int index, int value) {
    if (start == end) {
        tree[treeNode] = value;
        return;
    }

    int mid = (start + end) / 2;
    if (index <= mid) {
        update(tree, start, mid, 2 * treeNode, index, value);
    } else {
        update(tree, mid + 1, end, 2 * treeNode + 1, index, value);
    }

    tree[treeNode] = (tree[2 * treeNode] > tree[2 * treeNode + 1]) ? tree[2 * treeNode] : tree[2 * treeNode + 1];
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *segmentTree = (int *)malloc(4 * n * sizeof(int));
    buildSegmentTree(arr, segmentTree, 0, n - 1, 1);

    char operation[4];
    int l, r, i, v;

    while (1) {
        scanf("%s", operation);

        if (operation[0] == 'E') {
            break;
        } else if (operation[0] == 'M') {
            scanf("%d %d", &l, &r);
            printf("%d\n", query(segmentTree, 0, n - 1, 1, l, r));
        } else {
            scanf("%d %d", &i, &v);
            update(segmentTree, 0, n - 1, 1, i, v);
        }
    }

    free(arr);
    free(segmentTree);

    return 0;
}
