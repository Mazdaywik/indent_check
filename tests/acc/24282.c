#include <stdio.h>
#include <stdlib.h>

int *t;

void build(int v, int l, int r, int *arr) {
    if (l + 1 == r) {
        t[v] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v + 1, l, mid, arr);
    build(2 * v + 2, mid, r, arr);
    if (t[2 * v + 1] > t[2 * v + 2]) {
        t[v] = t[2 * v + 1];
    } else {
        t[v] = t[2 * v + 2];
    }
}

int get_max(int v, int l, int r, int a, int b) {
    if (b <= l || r <= a) {
        return -1e9;
    }
    if (a <= l && r <= b) {
        return t[v];
    }
    int mid = (l + r) / 2;
    int res1 = get_max(2 * v + 1, l, mid, a, b);
    int res2 = get_max(2 * v + 2, mid, r, a, b);
    if (res1 > res2) {
        return res1;
    } else {
        return res2;
    }
}

void update(int v, int l, int r, int idx, int x) {
    if (l + 1 == r) {
        t[v] = x;
        return;
    }
    int mid = (l + r) / 2;
    if (idx < mid) {
        update(2 * v + 1, l, mid, idx, x);
    } else {
        update(2 * v + 2, mid, r, idx, x);
    }
    if (t[2 * v + 1] > t[2 * v + 2]) {
        t[v] = t[2 * v + 1];
    } else {
        t[v] = t[2 * v + 2];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    t = (int*) malloc(4 * n * sizeof(int));
    build(0, 0, n, arr);
    int m;
    scanf("%d", &m);
    while (1) {
        char s[4];
        scanf("%s", &s);
        if (s[0] == 'M') {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%d\n", get_max(0, 0, n, a, b + 1));
        } else if (s[0] == 'U') {
            int idx, x;
            scanf("%d%d", &idx, &x);
            update(0, 0, n, idx, x);
        } else {
            break;
        }
    }
    free(arr);
    free(t);
    return 0;
}