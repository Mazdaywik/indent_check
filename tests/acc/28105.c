#include <stdio.h>

void SelectionSort(int arr[], int left, int right) {
    for (int i = left; i < right; ++i) {
        int min_ind = i;
        for (int j = i + 1; j <= right; ++j) {
            if (arr[j] < arr[min_ind]) {
                min_ind = j;
            }
        }
        if(min_ind != i) {
            int temp = arr[min_ind];
            arr[min_ind] = arr[i];
            arr[i] = temp;
        }
    }
}

void swap(int arr[], int ind1, int ind2) {
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

int Partition(int arr[], int low, int high) {
    int pivotValue = arr[high];
    int i = low;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivotValue) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, high);
    return i;
}

void QuickSortRec(int arr[], int left, int right, int m) {
    while (left < right) {
        if (right - left + 1 < m) {
            SelectionSort(arr, left, right);
            break; 
        }
        else {
            int pivot = Partition(arr, left, right);

            if (pivot - left < right - pivot) {
                QuickSortRec(arr, left, pivot - 1, m); 
                left = pivot + 1; 
            } else {
                QuickSortRec(arr, pivot + 1, right, m);
                right = pivot - 1; 
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    QuickSortRec(arr, 0, n - 1, m);

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
