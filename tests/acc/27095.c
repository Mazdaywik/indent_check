#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
//#define max(a, b) ((a) < (b) ? (b) : (a))
#define maxsz (int)1e6 + 1000
#define inf (int)1e9

int* tree;
int *a;

int maxx(int x, int y){
    return x < y ? y : x;
}

int gcd(int x, int y) {
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        tree[v] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(v * 2 + 1, l, mid);
    build(v * 2 + 2, mid, r);
    tree[v] = gcd(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void upd(int v, int pos, int x, int l, int r) {
    if (l + 1 == r) {
        tree[v] = x;
        return;
    }
    int mid = (l + r) / 2;
    if (mid > pos) {
        upd(v * 2 + 1, pos, x, l, mid);
    }
    else{
        upd(v * 2 + 2, pos, x, mid, r);
    }
    tree[v] = gcd(tree[v * 2 + 1], tree[v * 2 + 2]);
}

int query(int v, int l, int r, int lv, int rv) {
    if (rv <= l || lv >= r) {
        return 0;
    }
    if (l <= lv && rv <= r) {
        return tree[v];
    }
    int mid = (lv + rv) / 2;
    return gcd(query(v * 2 + 1, l, r, lv, mid), query(v * 2 + 2, l, r, mid, rv));
}

int main(){
    int n, m;
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    tree = (int*) malloc(4 * n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    build(0, 0, n);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = query(0, l, r + 1, 0, n);
        printf("%d\n", abs(ans));
    }
    free(a);
    free(tree);
    return 0;
}