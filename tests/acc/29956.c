#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

void radixSort_byte (int byte, union Int32 *arr, int n) {
    int count[1<<8] = {0};

    for (int j = 0; j < n; j++) {
        int k = arr[j].bytes[byte] ^ ((byte == 3) << 7);
        count[k]++;
    }

    for (int i = 1; i < 1<<8; i++)
        count[i] += count[i - 1];
    
    union Int32 sortedArr[n];
    for (int a = n - 1; a >= 0; a--) {
        int  k = arr[a].bytes[byte] ^ ((byte == 3) << 7);
        int c =  -- count[k];
        count[k] = c;
        sortedArr[c] = arr[a];
    }

    memcpy(arr, sortedArr, n * sizeof(union Int32));
}

void radixSort(union Int32 *arr, int n) {
	for (int i = 0; i < 4; i++) 
        radixSort_byte(i, arr, n);
}

int main() {
    int n;
    scanf("%d", &n);
    union Int32 arr[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i].x);

    radixSort(arr, n);

    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i].x);
    return 0;
}