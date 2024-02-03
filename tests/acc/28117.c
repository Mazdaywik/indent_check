#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

struct Task {
    int low, high;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSortIterative(int arr[], int low, int high) {
    struct Task stack[MAX_STACK_SIZE];

    int top = -1;

    stack[++top].low = low;
    stack[top].high = high;

    while (top >= 0) {
        low = stack[top].low;
        high = stack[top--].high;

        int pivot = partition(arr, low, high);

        if (pivot - 1 > low) {
            stack[++top].low = low;
            stack[top].high = pivot - 1;
        }

        if (pivot + 1 < high) {
            stack[++top].low = pivot + 1;
            stack[top].high = high;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        return 1;
    }


    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSortIterative(arr, 0, n - 1);


    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


    free(arr);

    return 0;
}