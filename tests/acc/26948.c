#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

const int maxsz = (int)1e5;

void simple_sort(int a[], int l, int r) {
    for (int i = l; i < r; ++i) {
        int minn = i;
        for (int j = i + 1; j < r; ++j) {
            if (a[j] < a[minn]) {
                minn = j;
            }
        }
        int tmp = a[i];
        a[i] = a[minn];
        a[minn] = tmp;
    }
}

void q_sort(int m, int a[], int l, int r) {
    if (r - l <= m) {
        simple_sort(a, l, r);
        return;
    }
    int piv = a[l + rand() % (r - l)], les = 0, eq = 0, gr = 0;
    for (int i = l; i < r; ++i) {
        if (a[i] < piv) {
            les++;
        }
        else if (a[i] == piv) {
            eq++;
        }
        else {
            gr++;
        }
    }
    int* a2 = (int*)malloc(sizeof(int) * (r - l));
    eq += les;
    gr += eq;
    for (int i = l; i < r; ++i) {
        if (a[i] < piv) {
            les -= 1;
            a2[les] = a[i];
        }
        else if (a[i] == piv) {
            eq -= 1;
            a2[eq] = a[i];
        }
        else {
            gr -= 1;
            a2[gr] = a[i];
        }
    }
    memcpy(a + l, a2, sizeof(int) * (r - l));
    free(a2);
    q_sort(m, a, l, l + eq);
    q_sort(m, a, l + gr, r);
}

int main(){
    int a[maxsz], n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    q_sort(m, a, 0, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}