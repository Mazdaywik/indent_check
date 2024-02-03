#include <stdio.h>
struct Task {
    int low, high;
};
void quicksort(int arr[], int n) {
    struct Task stack[n];
    int top = 0, low, high, i, j, temp;
    stack[top].low = 0;
    stack[top].high = n - 1;
    while (top >= 0) {
        low = stack[top].low;
        high = stack[top].high;
        top--;
        i = low;
        for (j = low; j < high; j++) {
            if (arr[j] < arr[high]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
            }
        }   
        temp = arr[i];
        arr[i] = arr[high];
        arr[high] = temp;
        if (i - 1 > low) {
            top++;
            stack[top].low = low;
            stack[top].high = i - 1;
        }
        if (i + 1 < high) {
            top++;
            stack[top].low = i + 1;
            stack[top].high = high;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}