#include <stdio.h>
long particion(long *arr, long low, long high) {
    long i = low, j, temp;
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
    return i;
}
void selectsort(long *arr, long start, long end) {
    long i, j, k, temp;
    for (j = end; j > start; j--) {
        k = j;
        for (i = j - 1; i >= start; i--) {
            if (arr[i] > arr[k]) k = i;
        }
        temp = arr[k];
        arr[k] = arr[j];
        arr[j] = temp;
    } 
}
void quicksort(long *arr, long left, long right, long m) {
    long border;
    if (left < right) {
        if ((right - left + 1) < m) selectsort(arr, left, right);
        else {
            border = particion(arr, left, right);
            quicksort(arr, left, border - 1, m);
            quicksort(arr, border + 1, right, m);
        }
    }
}
int main(int argc, char **argv)
{
    long n, i, m;
    scanf("%ld %ld", &n, &m);
    long arr[n];
    for (i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }
    quicksort(arr, 0, n - 1, m);
    for (i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }
    return 0;
}