#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int max(int x, int y) {
    if (x > y) return x;
    else return y;
}
void build_tree(int arr[], int l, int r, int* tree, int index) {
    if (l == r) tree[index] = arr[l];
    else {
        int m = (l + r) / 2;
        build_tree(arr, l, m, tree, 2 * index + 1);
        build_tree(arr, m + 1, r, tree, 2 * index + 2);
        tree[index] = max(tree[2 * index + 2], tree[2 * index + 1]);
    }
}

void update_tree(int i, int v, int l, int r, int* tree, int index) {
    if (l == r) tree[index] = v;
    else {
        int m = (l + r) / 2;
        if (i <= m) update_tree(i, v, l, m, tree, index * 2 + 1);
        else update_tree(i, v, m + 1, r, tree, index * 2 + 2);
        tree[index] = max(tree[index * 2 + 2], tree[index * 2 + 1]);
    }
}

int query_tree(int* tree, int l, int r, int a, int b, int index) {
    if ((a == l) && (b == r)) return tree[index];
    else {
        int m = (l + r) / 2;
        if (b <= m) return query_tree(tree, l, m, a, b, 2 * index + 1);
        else if (a > m) return query_tree(tree, m + 1, r, a, b, index * 2 + 2);
        else {
            return max(query_tree(tree, l, m, a, m, index * 2 + 1), query_tree(tree, m + 1, r, m + 1, b, index * 2 + 2));
        }
    }
}

int main() {
    int num1, num2, n;
    scanf("%d", &n);
    int* arr = malloc(sizeof(int) * n);
    int* tree = malloc(sizeof(int) * 2 * pow(2, ceil(log2(n))) - 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    build_tree(arr, 0, n - 1, tree, 0);
    char request[3];
    scanf("%s", request);
    while (strcmp(request, "END") != 0) {
        scanf("%d %d", &num1, &num2);
        if (strcmp(request, "MAX") == 0) {
            printf("%d\n", query_tree(tree, 0, n - 1, num1, num2, 0));
        }
        else if (strcmp(request, "UPD") == 0) {
            arr[num1] = num2;
            update_tree(num1, num2, 0, n - 1, tree, 0);
        }
        scanf("%s", request);
    }
    free(tree);
    free(arr);
    return 0;
}