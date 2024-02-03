#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int n;
int* t;

void build(int v, int l, int r, int* arr) {
    if (l + 1 == r) {
        if (l != 0 && l != n + 1 && arr[l] >= arr[l - 1] && arr[l] >= arr[l + 1]) {
            t[v] = 1;
        } else {
            t[v] = 0;
        }
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v + 1, l, mid, arr);
    build(2 * v + 2, mid, r, arr);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
}

int get_sum(int v, int l, int r, int a, int b) {
    if (b <= l || r <= a) {
        return 0;
    }
    if (a <= l && r <= b) {
        return t[v];
    }
    int mid = (l + r) / 2;
    int res1 = get_sum(2 * v + 1, l, mid, a, b);
    int res2 = get_sum(2 * v + 2, mid, r, a, b);
    return res1 + res2;
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
    t[v] = t[2 * v + 1] + t[2 * v + 2];
}

int main() {
    scanf("%d", &n);
    int* arr = (int*) malloc((n + 2) * sizeof(int));
    arr[0] = -1e9;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    arr[n + 1] = -1e9;
    t = (int*) malloc(4 * (n + 2) * sizeof(int));
    build(0, 0, n + 2, arr);
    while (1) {
        char s[5];
        scanf("%s", &s);
        if (s[0] == 'P') {
            int a, b;
            scanf("%d%d", &a, &b);
            a++, b++;
            int res = get_sum(0, 0, n + 2, a, b + 1);
            printf("%d\n", res);
        } else if (s[0] == 'U') {
            int idx, x;
            scanf("%d%d", &idx, &x);
            idx++;
            arr[idx] = x;
            if (arr[idx] >= arr[idx - 1] && arr[idx] >= arr[idx + 1]) {
                update(0, 0, n + 2, idx, 1);
            } else {
                update(0, 0, n + 2, idx, 0);
            }
            if (idx != 1) {
                if (arr[idx - 1] >= arr[idx - 2] && arr[idx - 1] >= arr[idx]) {
                    update(0, 0, n + 2, idx - 1, 1);
                } else {
                    update(0, 0, n + 2, idx - 1, 0);
                }
            }
            if (idx != n) {
                if (arr[idx + 1] >= arr[idx] && arr[idx + 1] >= arr[idx + 2]){ 
                    update(0, 0, n + 2, idx + 1, 1);
                } else {
                    update(0, 0, n + 2, idx + 1, 0);
                }
            }
        } else {
            break;
        }
    }
    free(arr);
    free(t);
    return 0;
}