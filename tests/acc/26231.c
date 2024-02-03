#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) 
{
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;
    int count_a = 0;
    int count_b = 0;
    const char *ptr_a = str_a;
    const char *ptr_b = str_b;
    while (*ptr_a != '\0') 
    {
        if (*ptr_a == 'a')
            count_a++;
        ptr_a++;
    }
    while (*ptr_b != '\0') 
    {
        if (*ptr_b == 'a')
            count_b++;
        ptr_b++;
    }
    return count_a - count_b;
}

void swap(void *a, void *b, size_t width) 
{
    char *p = a, *q = b, t;
    for (size_t i = 0; i < width; i++) 
    {
        t = p[i];
        p[i] = q[i];
        q[i] = t;
    }
}

void heapify(void *base, size_t nel, size_t width,
int (*compare)(const void *, const void *), size_t i) 
{
    char *arr = base;
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    if (left < nel && compare(&arr[left * width], &arr[largest * width]) > 0)
        largest = left;
    if (right < nel && compare(&arr[right * width], &arr[largest * width]) > 0)
        largest = right;
    if (largest != i) 
    {
        swap(&arr[i * width], &arr[largest * width], width);
        heapify(base, nel, width, compare, largest);
    }
}

void hsort(void *base, size_t nel, size_t width, int (*compare)(const void *, const void *)) 
{
    char *arr = base;
    for (long i = nel / 2 - 1; i >= 0; i--)
        heapify(base, nel, width, compare, i);
    for (size_t i = nel - 1; i > 0; i--) 
    {
        swap(&arr[0], &arr[i * width], width);
        heapify(base, i, width, compare, 0);
    }
}

int main() {
    size_t size;
    scanf("%zu", &size);
    const size_t buffer_size = 1000;
    char buffer[buffer_size];
    char *array[size];
    for (size_t i = 0; i < size; i++) {
        scanf("%s", buffer);
        array[i] = malloc(strlen(buffer) + 1);
        strcpy(array[i], buffer);
    }
    hsort(array, size, sizeof(char *), compare);
    for (size_t i = 0; i < size; i++) 
    {
        printf("%s\n", array[i]);
        free(array[i]);
    }
    return 0;
}