#include <stdio.h>
#include <stdlib.h>

#define ABS(a) ((a < 0) ? (-a) : (a)) 

void insertionSort(int arr[], int left, int right) {
   for (int i = left + 1; i <= right; i++) {
       int key = arr[i];
       int j = i - 1;

       while (j >= left && ABS(arr[j]) > ABS(key)) {
           arr[j + 1] = arr[j];
           j = j - 1;
       }

       arr[j + 1] = key;
   }
}

void merge(int arr[], int low, int mid, int high, int temp[]) {
    int i = low, j = mid + 1, h = 0;

    while (h < high - low + 1) {
        if (j <= high && (i == mid + 1 || ABS(arr[j]) < ABS(arr[i]))) {
            temp[h] = arr[j];
            j++;
        } else {
            temp[h] = arr[i];
            i++;
        }
        h++;
    }

    for (i = 0; i < h; i++) {
        arr[low + i] = temp[i];
    }
}

void mergeSortRec(int arr[], int low, int high, int temp[]) {
    if (low < high) {
        if (high - low + 1 < 5) {
            insertionSort(arr, low, high);
        } else {
            int mid = (low + high) / 2;
            if (mid - low + 1 < 5)
            {
                insertionSort(arr, low, mid);
            }
            else
            {
                mergeSortRec(arr, low, mid, temp);
            }

            if (high - mid < 5)
            {
                insertionSort(arr, mid + 1, high);
            }
            else
            {
                mergeSortRec(arr, mid + 1, high, temp);
            }
            merge(arr, low, mid, high, temp);
        }
    }
}

void mergeSort(int arr[], int n) {
    int *temp = (int*)malloc(n * sizeof(int));
    mergeSortRec(arr, 0, n - 1, temp);
    free(temp);
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }    

    mergeSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}