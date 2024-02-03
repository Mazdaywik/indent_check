#include <stdio.h>
#include <stdlib.h>
union Int32 {
    int x;
    unsigned char bytes[4];
};

void radixsort(union Int32 *arr, int n) {
    int count_pos[256] = {0}, count_neg[256] = {0}, i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < n; j++) {
            if (arr[j].x < 0)  count_neg[arr[j].bytes[i]]++;
            else count_pos[arr[j].bytes[i]]++;
        }
        for (j = 1; j < 256; j++) {
            count_neg[j] += count_neg[j - 1];
            count_pos[j] += count_pos[j - 1];
        }
        int k = 0;
        union Int32 res1[n], res2[n];
        for (j = n - 1; j >= 0; j--) {
            if (arr[j].x < 0) {
                res1[count_neg[arr[j].bytes[i]] - 1] = arr[j];
                count_neg[arr[j].bytes[i]]--;
                k++;
            }
        }
        for (j = n - 1; j >= 0; j--) {
            if (arr[j].x >= 0) {
                res2[count_pos[arr[j].bytes[i]] - 1] = arr[j];
                count_pos[arr[j].bytes[i]]--;
            }
        }
        for (j = 0; j < k; j++) {
            arr[j] = res1[j];
        }
        for (j = k; j < n; j++) {
            arr[j] = res2[j - k];
        }
        for (j = 0; j < 256; j++) {
            count_pos[j] = 0;
            count_neg[j] = 0;
        }
    }
}

int main(int argc, char **argv) {
    int n, i;
    scanf("%d", &n);
    union Int32 arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].x);
    }
    radixsort(arr, n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].x);
    }
    return 0;
}