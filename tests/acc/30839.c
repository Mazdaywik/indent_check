#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция сравнения для qsort
int compare(const void *a, const void *b) {
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;

    int count_a = 0, count_b = 0;
    for (int i = 0; str_a[i] != '\0'; ++i) {
        if (str_a[i] == 'a') {
            count_a++;
        }
    }
    for (int i = 0; str_b[i] != '\0'; ++i) {
        if (str_b[i] == 'a') {
            count_b++;
        }
    }

    return count_a - count_b;
}

// Функция обмена элементов в массиве
void swap(void *a, void *b, size_t width) {
    char *temp = malloc(width);
    if (temp == NULL) {
        // Обработка ошибки выделения памяти
        exit(EXIT_FAILURE);
    }

    memcpy(temp, a, width);
    memcpy(a, b, width);
    memcpy(b, temp, width);

    free(temp);
}

// Функция пирамидальной сортировки
void hsort(void *base, size_t nel, size_t width,
           int (*compare)(const void *a, const void *b)) {
    char *char_base = base;

    for (int i = nel / 2 - 1; i >= 0; --i) {
        for (int j = i; 2 * j + 1 < nel; j = 2 * j + 1) {
            int child = 2 * j + 1;
            if (child + 1 < nel && compare(char_base + child * width, char_base + (child + 1) * width) < 0) {
                ++child;
            }
            if (compare(char_base + j * width, char_base + child * width) < 0) {
                swap(char_base + j * width, char_base + child * width, width);
            } else {
                break;
            }
        }
    }

    for (int i = nel - 1; i > 0; --i) {
        swap(char_base, char_base + i * width, width);
        for (int j = i / 2 - 1; j >= 0; --j) {
            for (int k = j; 2 * k + 1 < i; k = 2 * k + 1) {
                int child = 2 * k + 1;
                if (child + 1 < i && compare(char_base + child * width, char_base + (child + 1) * width) < 0) {
                    ++child;
                }
                if (compare(char_base + k * width, char_base + child * width) < 0) {
                    swap(char_base + k * width, char_base + child * width, width);
                } else {
                    break;
                }
            }
        }
    }
}

int main() {
    int size;
    scanf("%d", &size);

    // Чтение массива строк
    char buffer[1000];
    char **array = malloc(size * sizeof(char *));
    if (array == NULL) {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; ++i) {
        scanf("%s", buffer);
        array[i] = malloc(strlen(buffer) + 1);
        if (array[i] == NULL) {
            exit(EXIT_FAILURE);
        }
        strcpy(array[i], buffer);
    }

    // Сортировка массива строк
    hsort(array, size, sizeof(char *), compare);

    // Вывод отсортированного массива
    for (int i = 0; i < size; ++i) {
        printf("%s\n", array[i]);
        free(array[i]);
    }

    free(array);

    return 0;
}
