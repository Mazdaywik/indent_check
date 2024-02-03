#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int mo(int y) {
    if (y < 0) return -1 * y;
    return y;
}

void merge(int k, int l, int m, int *base) {
    int *t = (int *)malloc(sizeof(int) * (m - k + 1));
    int i = k;
    int j = l + 1;
    int h = 0;
    while (h < m - k + 1) {
        if ((j <= m) && (i == l + 1 || mo(base[j]) < mo(base[i]))) {
            t[h] = base[j];
            j++;
        } else {
            t[h] = base[i];
            i++;
        }
        h++;
    }
    for (int p = 0; p < h; p++) {
        base[k + p] = t[p];
    }
    free(t);
}

void insertsort(int *base, int start, int end) {
    int i = 1;
    int elem;
    int loc;
    while (i < end - start + 1) {
        elem = base[i + start];
        loc = i - 1;
        while ((loc >= 0) && (mo(base[loc + start]) > mo(elem))) {
            base[loc + start + 1] = base[loc + start];
            loc = loc - 1;
        }
        base[loc + 1 + start] = elem;
        i++;
    }
}

void RECmergesort(int *base, int low, int hight) {
    if (hight - low < 4) {
        insertsort(base, low, hight);
    } else {
        if (low < hight) {
            int med = floor((low + hight) / 2);
            RECmergesort(base, low, med);
            RECmergesort(base, med + 1, hight);
            merge(low, med, hight, base);
        }
    }
}

void mergesort(int *base, int n) { RECmergesort(base, 0, n - 1); }

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    mergesort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}