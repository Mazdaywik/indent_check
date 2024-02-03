#include <stdio.h>
#include <stdlib.h>

union Int32 {
    int value;
    unsigned char byte[4];
};

void countingSort(int index, union Int32 *array, int size) {
    int count[256] = {0};
    union Int32 *output = malloc(size * sizeof(union Int32));
    for (int i = 0; i < size; i++) {
        int key = array[i].byte[index] ^ (index == 3 ? 128 : 0);
        count[key]++;
    }
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        int key = array[i].byte[index] ^ (index == 3 ? 128 : 0);
        output[count[key] - 1] = array[i];
        count[key]--;
    }
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
    free(output);
}

void radixSort(union Int32 *array, int size) {
    for (int i = 0; i < 4; i++) {
        countingSort(i, array, size);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    union Int32 *arr = malloc(n * sizeof(union Int32));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
    }
    radixSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].value);
    }
    free(arr);
    return 0;
}