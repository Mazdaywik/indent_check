#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;

    int count_a = 0, count_b = 0;

    for (int i = 0; i < (int)strlen(str_a); i++) {
        if (str_a[i] == 'a')
            count_a++;
    }

    for (int i = 0; i < (int)strlen(str_b); i++) {
        if (str_b[i] == 'a')
            count_b++;
    }

    return count_a - count_b;
}

void hsort(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b)) {
    char *arr = (char *)base;

    for (int i = nel / 2 - 1; i >= 0; i--) {
        int j = i;
        while (1) {
            int max_child = j;
            int left_child = 2 * j + 1;
            int right_child = 2 * j + 2;

            if (left_child < (int)nel && compare(&arr[left_child * width], &arr[max_child * width]) > 0)
                max_child = left_child;

            if (right_child < (int)nel && compare(&arr[right_child * width], &arr[max_child * width]) > 0)
                max_child = right_child;

            if (max_child == j)
                break;

            for (int k = 0; k < (int)width; k++) {
                char tmp = arr[j * width + k];
                arr[j * width + k] = arr[max_child * width + k];
                arr[max_child * width + k] = tmp;
            }

            j = max_child;
        }
    }

    for (int i = nel - 1; i > 0; i--) {
        for (int k = 0; k < (int)width; k++) {
            char tmp = arr[k];
            arr[k] = arr[i * width + k];
            arr[i * width + k] = tmp;
        }

        int j = 0;
        while (1) {
            int max_child = j;
            int left_child = 2 * j + 1;
            int right_child = 2 * j + 2;

            if (left_child < i && compare(&arr[left_child * width], &arr[max_child * width]) > 0)
                max_child = left_child;

            if (right_child < i && compare(&arr[right_child * width], &arr[max_child * width]) > 0)
                max_child = right_child;

            if (max_child == j)
                break;

            for (int k = 0; k < (int)width; k++) {
                char tmp = arr[j * width + k];
                arr[j * width + k] = arr[max_child * width + k];
                arr[max_child * width + k] = tmp;
            }

            j = max_child;
        }
    }
}

int main() {
    int size;
    char buffer[1000];

    scanf("%d", &size);

    char **str_array = (char **)malloc(size * sizeof(char *));

    for (int i = 0; i < size; i++) {
        scanf("%s", buffer);
        int len = strlen(buffer) + 1;
        str_array[i] = (char *)malloc(len * sizeof(char));
        strncpy(str_array[i], buffer, len);
    }

    hsort(str_array, size, sizeof(char *), compare);

    for (int i = 0; i < size; i++) {
        printf("%s ", str_array[i]);
        free(str_array[i]);
    }

    free(str_array);
    return 0;
}
