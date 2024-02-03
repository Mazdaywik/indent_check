#include <stdio.h>

void swap(int *arr, size_t a, size_t b)
{
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void SelectSort(int *arr, int n)
{
    int j = n - 1;
    while (j > 0) {
        int k = j;
        int i = j - 1;
        while (i >= 0) {
            if (arr[k] < arr[i]) {
                k = i;
            }
            i--;
        }
        swap(arr, j, k);
        j--;
    }
}

int Partion(int *arr, int low, int high)
{
    int i = low;
    int j = low;
    while (j <= high) {
        if (arr[high] > arr[j]) {
            swap(arr, i, j);
            i++;
        }
        j++;
    }
    swap(arr, i, high);
    return i;
}

void QuickSortRec(int *arr, int low, int high)
{
    label:
    if (low < high) {
        int q = Partion(arr, low, high);
        if ((q - low) < (high - q)) {
            QuickSortRec(arr, low, q - 1);
            low = q + 1;
        } else {
            QuickSortRec(arr, q + 1, high);
            high = q - 1;
        }
        goto label;
    }
}

void QuickSort(int *arr, int n, int m)
{
    if (n < m) SelectSort(arr, n);
    else QuickSortRec(arr, 0, n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int m;
    scanf("%d", &m);
    
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    QuickSort(arr, n, m);
    
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
