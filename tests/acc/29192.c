#include <stdio.h>
#include <stdlib.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

void countingSort(int base, int index, union Int32 *array, int size) {
    int *count = (int*)malloc(base * sizeof(int));
    union Int32 *result = (union Int32*)malloc(size * sizeof(union Int32));

    for (int i = 0; i < base; i++)
        count[i] = 0;

    for (int i = 0; i < size; i++) {
        int key = (index == 3) ? (array[i].bytes[index] + 128) % base : array[i].bytes[index];
        count[key]++;
    }

    for (int i = 1; i < base; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        int key = (index == 3) ? (array[i].bytes[index] + 128) % base : array[i].bytes[index];
        int j = --count[key];
        result[j] = array[i];
    }

    for (int i = 0; i < size; i++)
        array[i] = result[i];

    free(count);
    free(result);
}

void radixSort(int base, int size, union Int32 *array) {
    for (int i = 0; i < 4; i++)
        countingSort(base, i, array, size);
}

int main() {
    int n;
    scanf("%i", &n);

    union Int32 *array = (union Int32*)malloc(n * sizeof(union Int32));

    for (int i = 0; i < n; i++) {
        scanf("%i", &array[i].x);
        for (int j = 0; j < 4; j++)
            array[i].bytes[j] = (array[i].x >> (j * 8)) & 0xFF;
    }

    radixSort(256, n, array);

    for (int i = 0; i < n; i++)
        printf("%i ", array[i].x);

    printf("\n");

    free(array);
    return 0;
}
