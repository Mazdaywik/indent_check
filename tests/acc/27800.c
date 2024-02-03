#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <malloc.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

// Cмещаем знаковый бит для корректной работы с отрицательными числами
int getByte(union Int32 key, int byteIndex) {
    if (byteIndex == 3) {
        return (int)(key.bytes[byteIndex] ^ 0x80);
    } else {
        return (int)key.bytes[byteIndex];
    }
}

// Сортировка подсчетом для определенного байта
void countingSort(union Int32 *array, int size, int byteIndex) {
    int output[size];
    int count[256] = {0};
    int i;
    union Int32 temp;

    for (i = 0; i < size; i++) {
        count[getByte(array[i], byteIndex)]++;
    }

    for (i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--) {
        temp = array[i];
        output[count[getByte(temp, byteIndex)] - 1] = temp.x;
        count[getByte(temp, byteIndex)]--;
    }

    for (i = 0; i < size; i++) {
        array[i].x = output[i];
    }
}

// Функция поразрядной сортировки
void radixSort(union Int32 *array, int size) {
    for (int byteIndex = 0; byteIndex < 4; byteIndex++) {
        countingSort(array, size, byteIndex);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    union Int32 *array = (union Int32 *)malloc(n * sizeof(union Int32));

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i].x);
    }

    radixSort(array, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i].x);
    }

    free(array);
    return 0;
}