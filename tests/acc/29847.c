#include <stdio.h>
#include <stdlib.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

void DistributionSort(int key, union Int32 *arr, int n) {
    int *count = calloc(256, sizeof(int));
    int j = 0;
    while (j < n) {
        int k = arr[j].bytes[key];
        if (key == 3) {
            k += (arr[j].x < 0) ?  (- 128) :  128;
        } else {
            k = arr[j].bytes[key];
        }
        count[k] += 1;
        j += 1;
    }
    int i = 1;
    while (i < 256) {
        count[i] += count[i-1];
        i += 1;
    }
    union Int32 *sorted_arr = malloc(n * sizeof(union Int32));
    j = n - 1;
    while (j >= 0) {
        int k = arr[j].bytes[key];
        if (key == 3) {
            k += (arr[j].x < 0) ?  (- 128) :  128;
        } else {
            k = arr[j].bytes[key];
        }
        i = count[k] - 1;
        count[k] = i;
        sorted_arr[i] = arr[j];
        --j;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = sorted_arr[i];
    }
    free(sorted_arr);
    free(count);
}


void RadixSort(int q, union Int32 *arr, int n) {
    for (int i = 0; i < q; ++i) {
        DistributionSort(i, arr, n);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i].x);
    }
    
}

int main() {
    int n;
    scanf("%d", &n);
    union Int32 *arr = calloc(n, sizeof(union Int32));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i].x);
    }
    RadixSort(4, arr, n);
    free(arr);
}