#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

const int maxsz = (int)1e5;

void ins_sort(int a[], int a2[], int l, int r) {
    for (int i = l + 1; i < r; ++i) {
        for (int j = i - 1; j >= l && (abs(a[j + 1]) < abs(a[j])); --j) {
            int tmp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = tmp;
        }
    }
}

void mrg_sort(int a[], int a2[], int l, int r) {
    if (r - l <= 5) {
        ins_sort(a, a2, l, r);
        return;
    }
    int m = (r + l) / 2;
    mrg_sort(a, a2, l, m);
    mrg_sort(a, a2, m, r);
    int l_cur = l, r_cur = m, ind = 0;
    while (l_cur < m && r_cur < r) {
        if (abs(a[l_cur]) <= abs(a[r_cur])) {
            a2[ind] = a[l_cur];
            l_cur += 1;
        } else {
            a2[ind] = a[r_cur];
            r_cur += 1;
        }
        ind += 1;
    }
    while (l_cur < m) {
        a2[ind] = a[l_cur];
        ind += 1;
        l_cur += 1;
    }
    while (r_cur < r) {
        a2[ind] = a[r_cur];
        ind += 1;
        r_cur += 1;
    }
    for (int i = 0; l < r; ++i) {
        a[l] = a2[i];
        l += 1;
    }
}

int main(){
    int a[maxsz], a2[maxsz], n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    mrg_sort(a, a2, 0, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}