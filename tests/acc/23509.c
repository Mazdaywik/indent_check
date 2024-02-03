#include <stdio.h>
#include <stdlib.h>

// Функция сравнения двух элементов
int compare(void* a, void* b) {
    int* elemA = (int*)a;
    int* elemB = (int*)b;

    if (*elemA < *elemB) {
        return -1;
    }
    else if (*elemA > *elemB) {
        return 1;
    }
    else {
        return 0;
    }
}

// Функция для поиска максимального элемента в массиве
int maxarray(void* base, size_t nel, size_t width, 
    int (*compare)(void*, void*)) {
    char* arr = base; // Указатель на начало массива
    int maxIndex = 0; // Индекс максимального элемента

    for (size_t i = 1; i < nel; i++) {
        if (compare(arr + i * width, arr + maxIndex * width) > 0) {
            maxIndex = i; // Обновление индекса максимального элемента
        }
    }

    return maxIndex;
}

int main() {
    int array[] = { 5, 2, 9, 1, 7 }; // Исходный массив
    size_t nel = sizeof(array) / sizeof(array[0]); // Количество элементов в массиве

    int maxIndex = maxarray(array, nel, sizeof(array[0]), compare); // Поиск индекса максимального элемента

    printf("Max element index: %d\n", maxIndex);
    printf("Max element value: %d\n", array[maxIndex]);

    return 0;
}