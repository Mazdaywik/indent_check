#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct {
    int *tree;
    int size;
} SegTree;

int max(int a, int b);
int min(int a, int b);

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void create(SegTree *st, int *arr, int v, int tl, int tr) {
    if (tl == tr) {
        st->tree[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        create(st, arr, v*2, tl, tm);
        create(st, arr, v*2+1, tm+1, tr);
        st->tree[v] = max(st->tree[v*2], st->tree[v*2+1]);
    }
}

void segtree_creator(SegTree *st, int *arr, int n) {
    st->size = n;
    st->tree = (int *)malloc(4 * n * sizeof(int));
    if (st->tree == NULL) {
        fprintf(stderr, "\n");
        exit(EXIT_FAILURE);
    }
    create(st, arr, 1, 0, n-1);
}

void update(SegTree *st, int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        st->tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(st, v*2, tl, tm, pos, new_val);
        else
            update(st, v*2+1, tm+1, tr, pos, new_val);
        st->tree[v] = max(st->tree[v*2], st->tree[v*2+1]);
    }
}

void segtree_update(SegTree *st, int pos, int new_val) {
    update(st, 1, 0, st->size-1, pos, new_val);
}

int request(SegTree *st, int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l == tl && r == tr) {
        return st->tree[v];
    }
    int tm = (tl + tr) / 2;
    return max(request(st, v*2, tl, tm, l, min(r, tm)),
               request(st, v*2+1, tm+1, tr, max(l, tm+1), r));
}

int segtree_request(SegTree *st, int l, int r) {
    return request(st, 1, 0, st->size-1, l, r);
}

int main() {
    int n; 
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "яти\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    SegTree st;
    segtree_creator(&st, arr, n);

    char command[4];
    while (scanf("%s", command) != EOF) {
        if (command[0] == 'E' && command[1] == 'N' && command[2] == 'D') break;
        int a, b;
        if (command[0] == 'M') {
            scanf("%d %d", &a, &b);
            printf("%d\n", segtree_request(&st, a, b));
        } else if (command[0] == 'U') { 
            scanf("%d %d", &a, &b);
            segtree_update(&st, a, b);
        }
    }
    free(arr);
    free(st.tree);
    return 0;
}