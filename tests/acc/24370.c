#include <stdio.h>
#include <string.h>

void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}

void swap(int* x, int* y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[r]);
    return i + 1;
}

void quick_sort(int a[], int l, int r) {
    if (l < r) {
        int pivot_index = partition(a, l, r);

        quick_sort(a, l, pivot_index - 1);
        quick_sort(a, pivot_index + 1, r);
    }
}

int main() {
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (m < 5) {
        selection_sort(a, n);
    } else {
        quick_sort(a, 0, n - 1);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}