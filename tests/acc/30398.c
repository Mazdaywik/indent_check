#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

const int maxsz = (int)1e6;

void simple_sort(int a[], int l, int r) {
    //printf("%d\n", r);
    for (int i = l; i <= r; ++i) {
        int minn = i;
        for (int j = i + 1; j <= r; ++j) {
            if (a[j] < a[minn]) {
                minn = j;
            }
        }
        int tmp = a[i];
        a[i] = a[minn];
        a[minn] = tmp;
    }
}

int partition(int a[], int l, int r){
    int i = l, piv = a[r];
    for (int j = l; j < r; j++) {
        if (a[j] <= piv) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
        }
    }
    int tmp = a[i];
    a[i] = a[r];
    a[r] = tmp;
    return i;
}

void q_sort(int m, int a[], int l, int r) {
    if (r - l <= m){
        simple_sort(a, l, r);
        return;
    }
    while (l < r) {
        int q = partition(a, l, r);
        if (q - l < r - q) {
            q_sort(m, a, l, q - 1);
            l = q + 1;
        }
        else {
            q_sort(m, a, q + 1, r);
            r = q - 1;
        }
    }
}

int main(){
    int a[maxsz], n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    q_sort(m, a, 0,  n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}