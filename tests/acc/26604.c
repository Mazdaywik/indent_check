#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int partition(int f, int l, int *arr)
{
    int i = f, j = f, elem;
    while (i < l)
    {
        if (arr[i] < arr[l])
        {
            elem = arr[j];
            arr[j] = arr[i];
            arr[i] = elem;

            j++;
        }
        i++;
    }
    elem = arr[j];
    arr[j] = arr[l];
    arr[l] = elem;
    return j;
}


void select_sort(int f, int l, int* arr)
{
    int max_ind, i, elem;
    while (l > f)
    {
        max_ind = l;
        i = l - 1;
        while (i >= f)
        {
            if (arr[max_ind] < arr[i]) max_ind = i;
            i--;
        }
        elem = arr[l];
        arr[l] = arr[max_ind];
        arr[max_ind] = elem;
        l--;    
    }
    
}


void quick_sort(int f, int l, int *arr, int m)
{
label:
    if (f + m < l)
    {
        int q = partition(f, l, arr);
        if (q - f < l - q)
        {
            quick_sort(f, q-1, arr, m);
            f = q + 1;
        }
        else
        {
            quick_sort(q+1, l, arr, m);
            l = q - 1;
        }
        goto label;
    }
    if (f < l)
    {
        select_sort(f, l, arr);
    }
}


int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int arr[n];
    for (int i = 0; i < n ; i++)
    {
        scanf("%d", &arr[i]);
    }
    quick_sort(0, n-1, arr, m);
    for (int i = 0; i < n ; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
