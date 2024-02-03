#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void sort(int l, int r, int m, int *arr) {
    if (r - l + 1 <= m) {
        for (int i = l; i <= r; i++) {
            for (int j = i; j <= r; j++) {
                if (arr[i] > arr[j]) {
                    int x = arr[i];
                    arr[i] = arr[j];
                    arr[j] = x;
                }
            }
        }
        return;
    }
    int mid = arr[(l + r) / 2];
    int tmp1 = l, tmp2 = r;
    while (tmp1 <= tmp2) {
        while (arr[tmp1] < mid) {
            tmp1++;
        }
        while (arr[tmp2] > mid) {
            tmp2--;
        }
        if (tmp1 >= tmp2) {
            break;
        }
        int x = arr[tmp1];
        arr[tmp1] = arr[tmp2];
        arr[tmp2] = x;
        tmp1++, tmp2--;
    }
    sort(l, tmp2, m, arr);
    sort(tmp2 + 1, r, m, arr);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int* arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(0, n - 1, m, arr);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}