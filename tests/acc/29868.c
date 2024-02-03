#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1001

void swap(const void *a, const void *b, size_t width)
{
    for (int i = 0; i < width; i++) {
        char t = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = t;
    }
}

int compare (char *a, char *b)
{
    int pa = 0;
    for (int i = 0; i < strlen(a); i++)
        if (a[i] == 'a') pa++;
    
    int pb = 0;
    for (int i = 0; i < strlen(b); i++)
        if (b[i] == 'a') pb++;
    
    return (pa - pb);
}

void heapify (void *base, size_t nel, size_t width, size_t i,
             int (*compare)(const void *a, const void *b))
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < nel)
        if (compare((char*)base + left * width,
                    (char*)base + largest * width) > 0)
            largest = left;
    
    if (right < nel)
        if (compare((char*)base + right * width,
                    (char*)base + largest *width) > 0)
            largest = right;

    if (largest != i) {
        swap((char*)base + width * i, (char*)base + width * largest, width);
        heapify(base, nel, width, largest, compare);
    }
}


void hsort (void *base, size_t nel, size_t width,
    int (*compare)(const void *a, const void *b))
{
    for (int i = nel / 2 - 1; i >= 0; i--)
        heapify(base, nel, width, i, compare);
    
    for (int i = nel - 1; i >= 0; i--) {
        swap((char*)base + width * i, (char*)base, width);
        heapify(base, i, width, 0, compare);
    }
}


int main()
{
    int n;
    scanf("%d ", &n);
    
    char strs[n][SIZE];
    for (int i = 0; i < n; i++) scanf("%s", strs[i]);
    
    hsort(strs, n, SIZE, compare);
    
    for(int i = 0; i < n; i++) printf("%s ", strs[i]);
    return 0;
}

