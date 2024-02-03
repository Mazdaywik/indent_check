#include <stdio.h>

union Int32
{
    int x;
    unsigned char bytes[4];
};

void radixsort(union Int32 *arr, int n)
{
    for (int i = 0; i < 4; ++i)
    {
        int count[256];
        for (int j = 0; j < 256; ++j)
        {
            count[j] = 0;
        }
        for (int j = 0; j < n; ++j)
        {
            if (i == 3)
            {
                count[arr[j].bytes[i] ^ 128]++;
            }
            else
            {
                count[arr[j].bytes[i]]++;
            }
        }
        for (int j = 0; j < 255; ++j)
        {
            count[j + 1] += count[j];
        }
        union Int32 sorted[n];
        for (int j = n-1;j>=0; --j)
        {
            if (i == 3)
            {
                sorted[--count[arr[j].bytes[i] ^ 128]] = arr[j];
            }
            else
            {
                sorted[--count[arr[j].bytes[i]]] = arr[j];
            }
        }
        for (int j = 0; j < n; ++j)
        {
            arr[j] = sorted[j];
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    union Int32 arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i].x);
    }
    radixsort(arr, n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i].x);
    }
    return 0;
}