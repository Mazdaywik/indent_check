#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int compare (const void * a, const void * b)
{
    char* str_a = *(char**) a;
    char* str_b = *(char**) b;
    long long sum_a = 0, sum_b = 0, i = 0;
    while (str_a[i] != '\0')
    {
        if (str_a[i] == 'a') sum_a++;
        i++;
    }
    i = 0;
    while (str_b[i] != '\0')
    {
        if (str_b[i] == 'a') sum_b++;
        i++;
    }
    return sum_a - sum_b;
}

void hsort(void *base, size_t nel, size_t width,
        int (*compare)(const void *a, const void *b))
{
    void swap(char *a, char *b, long long width)
    {
        char *elem = malloc(width);
        memcpy(elem, a, width);
        memcpy(a, b, width);
        memcpy(b, elem, width);
        free(elem);
    }


    void heapify(long long i, long long n)
    {
        long long l, r, j = i + 1, elem;
        while (1)
        {
            l = 2 * (i + 1) - 1;
            r = 2 * (i + 1);
            j = i;
            if (n > l) if (compare((char*) base + width * l, (char*) base + width * i) > 0) i = l;
            if (n > r) if (compare((char*) base + width * r, (char*) base + width * i) > 0) i = r;
            if (i == j) break;
            swap((char*) base + i * width, (char*) base + j * width, width);
        }        
    }


    void build_heap(long long n)
    {
        long long i = n / 2 - 1;
        while (i >= 0)
        {
            heapify(i, n);
            i--;
        }
        
    }

    
    build_heap(nel);
    long long i = nel - 1, elem;
    while (i > 0)
    {
        swap(base, (char*) base + width * i, width);
        heapify(0, i);
        i--;
    }
}


int main() {
    long long n;
    scanf("%lld", &n);
    char* arr[n];
    


    for (int i = 0; i < n; i++)
    {
        arr[i] = (char*) malloc(1010 * sizeof(char));
        scanf("%s", arr[i]);
        // printf("%lu\n", strlen(m[i]));
        
    }


    hsort(arr, n, sizeof(arr[0]), compare);
    for (long long i = 0; i < n; i++)
    {
        printf("%s ", arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
        
    }
    return 0;
}


