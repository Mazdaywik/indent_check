#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quicksort(int arr[], int n, int m) {
    while (n > 1) {
        int i = 0;
        int j = n - 1;
        int baza = arr[n / 2];

        while (i <= j) {
            while (arr[i] < baza) {
                i++;
            }
            while (arr[j] > baza) {
                j--;
            }
            if (i <= j) {
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        }

        if (j + 1 > m) {
            quicksort(arr, j + 1, m);
        }
        else {
            int k, pos, tmp;
            for (k = 1; k < j + 1; k++) {
                tmp = arr[k];
                pos = k - 1;
                while (pos >= 0 && arr[pos] > tmp) {
                    arr[pos + 1] = arr[pos];
                    pos--;
                }
                arr[pos + 1] = tmp;
            }
        }
        arr += i;
        n -= i;
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

    quicksort(arr, n, m);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}