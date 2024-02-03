#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define RANGE 256
#define AMOUNT_BYTES 4

union Int32 {
    int x;
    unsigned char bytes[AMOUNT_BYTES];
};

void xorBits(union Int32* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        array[i].x ^= INT_MIN;
    }
}

void swapPtrInt32(union Int32** a, union Int32** b) {
    union Int32* temp = *a;
    *a = *b;
    *b = temp;
}

void radixSort(union Int32* array, size_t size) {
    int counter[RANGE] = {0};
    union Int32* buffer = calloc(size, sizeof(union Int32));

    xorBits(array, size);

    for (size_t nbyte = 0; nbyte < AMOUNT_BYTES; ++nbyte) {
        memset(counter, 0, RANGE * sizeof(int));

        for (size_t i = 0; i < size; ++i) {
            counter[array[i].bytes[nbyte]]++;
        }

        int start_index = 0;
        for (int i = 0; i < RANGE; ++i) {
            int count = counter[i];
            counter[i] = start_index;
            start_index += count;
        }

        for (size_t i = 0; i < size; ++i) {
            size_t position = array[i].bytes[nbyte];
            buffer[counter[position]].x = array[i].x;
            counter[position]++;
        }

        swapPtrInt32(&array, &buffer);
    }

    if (AMOUNT_BYTES % 2 != 0) {
        memcpy(buffer, array, size * sizeof(union Int32));
        array = buffer;
    }

    xorBits(array, size);

    free(buffer);
}

int main() {
    size_t size;
    scanf("%zu", &size);

    union Int32* array = calloc(size, sizeof(union Int32));

    for (size_t i = 0; i < size; ++i) {
        scanf("%d", &array[i].x);
    }

    radixSort(array, size);

    for (size_t i = 0; i < size; ++i) {
        printf("%d ", array[i].x);
    }

    printf("\n");
    free(array);

    return 0;
}