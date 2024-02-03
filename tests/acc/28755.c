#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int l_arr = m - l;
    int r_arr = r - m;

    int L[l_arr], R[r_arr];

    for (int i = 0; i < l_arr; i++)
    {
        L[i] = arr[l + i];
        R[i] = arr[m + i];
    }
    for (int j = l_arr; j < r_arr; j++)
    {
        R[j] = arr[m + j];
    }
    int i = 0, j = 0;
    while (i < l_arr & j < r_arr)
    {
        if (abs(L[i]) <= abs(R[j]))
        {
            arr[l] = L[i];
            i++;
        }
        else
        {
            arr[l] = R[j];
            j++;
        }
        l++;
    }

    if (i == l_arr)
    {
        while (j < r_arr)
        {
            arr[l] = R[j];
            j++;
            l++;
        }
    }
    else
    {
        while (i < l_arr)
        {
            arr[l] = L[i];
            i++;
            l++;
        }
    }
}

void sort(int arr[], int l, int r)
{
    for (int i = l + 1; i < r; i++)
    {
        int j = i;
        int elem;
        while (j > l & abs(arr[j - 1]) > abs(arr[j]))
        {
            elem = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = elem;
            j--;
        }
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l + 5 <= r)
    {
        int m = (r + l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m, r);

        merge(arr, l, m, r);
        return;
    }
    if (l < r)
    {
        sort(arr, l, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}