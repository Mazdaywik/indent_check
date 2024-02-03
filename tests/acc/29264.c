#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertionSort(int arr[], int start, int len);
void Merge(int arr[], int startLeft, int endLeft, int startRight, int endRight, int temp[]);
void RecursiveMergeSort(int arr[], int start, int end, int temp[]);
void Sort(int arr[], int len);

void InsertionSort(int arr[], int start, int len) {
    for (int idx = start + 1; idx < start + len; ++idx) {
        int value = arr[idx];
        int pos = idx - 1;

        while (pos >= start && abs(arr[pos]) > abs(value)) {
            arr[pos + 1] = arr[pos];
            --pos;
        }
        arr[pos + 1] = value;
    }
}

void Merge(int arr[], int startLeft, int endLeft, int startRight, int endRight, int temp[]) {
    int i = startLeft, j = startRight, k = 0;
    while (i < endLeft && j < endRight) {
        temp[k++] = (abs(arr[i]) <= abs(arr[j])) ? arr[i++] : arr[j++];
    }
    while (i < endLeft) temp[k++] = arr[i++];
    while (j < endRight) temp[k++] = arr[j++];

    for (int idx = 0; idx < k; ++idx) {
        arr[startLeft + idx] = temp[idx];
    }
}

void RecursiveMergeSort(int arr[], int start, int end, int temp[]) {
    if (end - start < 2) return;

    int len = end - start;
    if (len < 5) {
        InsertionSort(arr, start, len);
        return;
    }

    int mid = start + len / 2;
    RecursiveMergeSort(arr, start, mid, temp);
    RecursiveMergeSort(arr, mid, end, temp);
    Merge(arr, start, mid, mid, end, temp);
}

void Sort(int arr[], int len) {
    int* temp = malloc(len * sizeof(int));
    RecursiveMergeSort(arr, 0, len, temp);
    free(temp);
}

int main() {
    int len;
    scanf("%d", &len);
    int* arr = malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    Sort(arr, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0; 
}