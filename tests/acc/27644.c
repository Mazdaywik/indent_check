#include <stdio.h>
#include <stdlib.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

unsigned char extract_byte_key(union Int32 *entry, int byte) {
    unsigned char key = entry->bytes[byte];
    if (byte == 3) { 
        key ^= 0x80;
    }
    return key;
}

union Int32* dsort(union Int32 *arr, int n, int byte) {
    int count[256] = {0};
    union Int32 *sorted = malloc(n * sizeof(union Int32));
    for (int i = 0; i < n; i++) {
        count[extract_byte_key(&arr[i], byte)]++;
    }
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        sorted[--count[extract_byte_key(&arr[i], byte)]] = arr[i];
    }
    free(arr);
    return sorted;
}

union Int32* radixsort(union Int32 *arr, int n) {
    for (int byte = 0; byte < 4; byte++) {
        arr = dsort(arr, n, byte);
    }
    return arr;
}

int main() {
    int n;
    scanf("%d", &n);
    union Int32 *arr = malloc(n * sizeof(union Int32));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].x);
    }
    arr = radixsort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].x);
    }
    free(arr);
    return 0;
} 