#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void merge_sort(int l, int r, int *a) {
    if (r - l + 1 < 5) {
        for (int i = l + 1; i <= r; i++) {
            int j = i - 1;
            int x = a[i];
            while (j >= l && abs(a[j]) > abs(x)) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = x;
        }
        return;
    }
    int mid = (l + r) / 2;
    merge_sort(l, mid, a);
    merge_sort(mid + 1, r, a);
    int *tmp = malloc((r - l + 1) * sizeof(int));
    int i = l, j = mid + 1;
    int idx = 0;
    while (i <= mid || j <= r) {
        if (i == mid + 1) {
            tmp[idx] = a[j];
            idx++;
            j++;
        } else if (j == r + 1) {
            tmp[idx] = a[i];
            idx++;
            i++;
        } else {
            if (abs(a[i]) <= abs(a[j])) {
                tmp[idx] = a[i];
                idx++;
                i++;
            } else {
                tmp[idx] = a[j];
                idx++;
                j++;
            }
        }
    }
    for (int i = 0; i < r - l + 1; i++) {
        a[i + l] = tmp[i];
    }
    free(tmp);
}

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    int* a = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    merge_sort(0, n - 1, a);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}