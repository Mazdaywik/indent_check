#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(const void *a, const void *b) {
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;

    int count_a = 0, count_b = 0;

    for (const char *ptr = str_a; *ptr != '\0'; ++ptr) {
        if (*ptr == 'a') {
            count_a++;
        }
    }

    for (const char *ptr = str_b; *ptr != '\0'; ++ptr) {
        if (*ptr == 'a') {
            count_b++;
        }
    }

    return count_a - count_b;
}

void hsort(void *base, size_t nel, size_t width,
           int (*compare)(const void *a, const void *b)) {
    char *array = (char *)base;

    for (int i = nel / 2 - 1; i >= 0; i--) {
        int current = i;
        while (2 * current + 1 < nel) {
            int child = 2 * current + 1;
            if (child + 1 < nel && compare(array + (child + 1) * width, array + child * width) > 0) {
                child++;
            }

            if (compare(array + current * width, array + child * width) < 0) {
                for (size_t j = 0; j < width; j++) {
                    char temp = array[current * width + j];
                    array[current * width + j] = array[child * width + j];
                    array[child * width + j] = temp;
                }
                current = child;
            } else {
                break;
            }
        }
    }

    for (int i = nel - 1; i > 0; i--) {
        for (size_t j = 0; j < width; j++) {
            char temp = array[0 * width + j];
            array[0 * width + j] = array[i * width + j];
            array[i * width + j] = temp;
        }

        int current = 0;
        while (2 * current + 1 < i) {
            int child = 2 * current + 1;
            if (child + 1 < i && compare(array + (child + 1) * width, array + child * width) > 0) {
                child++;
            }

            if (compare(array + current * width, array + child * width) < 0) {
                for (size_t j = 0; j < width; j++) {
                    char temp = array[current * width + j];
                    array[current * width + j] = array[child * width + j];
                    array[child * width + j] = temp;
                }
                current = child;
            } else {
                break;
            }
        }
    }
}

int main() {
    int size;
    scanf("%d", &size);

    char **array = malloc(size * sizeof(char *));
    if (array == NULL) {
        return 1;
    }

    for (int i = 0; i < size; i++) {
        array[i] = malloc(1000); 
        if (array[i] == NULL) {
            return 1;
        }
        scanf("%s", array[i]);
    }
    hsort(array, size, sizeof(char *), compare_strings);

    for (int i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }

    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
