#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void direct_selection_sort(int *arr, int low, int high) {
    for (int i = low; i <= high; i++) {
        int min_index = i;
        for (int j = i + 1; j <= high; j++) 
            if (arr[j] < arr[min_index]) 
                min_index = j;
        swap((arr + i), (arr + min_index));
    }
}
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap((arr + i), (arr + j));
        }
    }
    swap((arr + i + 1), (arr + high));
    return (i + 1);
}

void quicksort(int *arr, int low, int high, int m) {
    if (low < high) {
        if (high - low + 1 < m) 
            direct_selection_sort(arr, low, high);
        else {
            int pi = partition(arr, low, high);
            quicksort(arr, low, pi - 1, m);
            quicksort(arr, pi + 1, high, m);
        }
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n - 1, m);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
