#include <stdio.h>
#include <stdlib.h>
#include<string.h>

union Int32 
{
    int x;
    unsigned char bytes[4];
};


int get_value(union Int32 *arr, int key, long i)
{
    if (key == 3)
    {
        if (arr[i].x >= 0)
        {
            return 128 + (int) arr[i].bytes[key];
        }
        return (int) arr[i].bytes[key] - 128;
    }
    return arr[i].bytes[key];
}


void dsort(union Int32* arr, union Int32 *new_arr, int k, long len)
{
    long long count_list[256];
    for (long long i = 0; i < 256; i++) count_list[i] = 0;
    long n = 0;
    for (long i = 0; i < len; i++)
    {
        count_list[get_value(arr, k, i)]++;
        n++;
    }
    for (int i = 1; i < 256; i++)
    {
        count_list[i] += count_list[i-1];
    }
    
    long i = len - 1;
    long j;
    int x;
    while (i >= 0)
    {
        j = count_list[get_value(arr, k, i)] - 1;
        count_list[get_value(arr, k, i)]--;
        new_arr[j] = arr[i];
        i--;
    }
}


void radixsort(union Int32 *arr, union Int32 *new_arr, int k, long len)
{
    if (k > 0) 
    {
        dsort(arr, new_arr, 0, len);
        for (int i = 0; i < len; i++)
        {
            arr[i] = new_arr[i];
        }
    }
    for (int i = 1; i < k; i++)
    {
        dsort(arr, new_arr, i, len);
        for (int i = 0; i < len; i++)
        {
            arr[i] = new_arr[i];
        }
    }
}


int main() {
    int n;
    scanf("%d", &n);
    union Int32 arr[n];
    union Int32 new_arr[n];
    
    int elem;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].x);
    }
    radixsort(arr, new_arr, 4, n);
    for (long i = 0; i < n; i++)
    {
        printf("%d\n", new_arr[i].x);
    }
    return 0;
}

