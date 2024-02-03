#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void selectionSort(int arr[], int low, int high) {
    int j = high;
    while (j > low) {
        int k = j;
        int i = j - 1;
        while (i >= low) {
            if (arr[k] < arr[i]) k = i;
            i--;
        }
        swap(arr, j, k);
        j--;
    }
}

int partition(int a[], int low, int high)
{
    int elem = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < elem) {
            i++;
            swap(a, i, j);
        }
    }
    swap(a, i+1, high);
    return i+1;
}

void quickSort(int a[], int low, int high, int m)
{
    while (low < high) {
        if (high - low < m) {
            selectionSort(a, low, high);
            break;
        } else {
            int op = partition(a, low, high);
            if (op - low < high - op) {
                quickSort(a, low, op - 1, m);
                low = op + 1;
            } else {
                quickSort(a, op + 1, high, m);
                high = op - 1;
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for (int i = 0; i<n; i++) scanf("%d", &a[i]);
    quickSort(a, 0, n - 1, m);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}