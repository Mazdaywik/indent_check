#include <stdio.h>
#include <stdlib.h>
void merge(long *arr, long left, long mid, long right)
{
    long i = left, j = mid + 1, h = 0, help_arr[right - left + 1];
    while (h < right - left + 1) {
        if ((j <= right) && ((i == mid + 1) || (abs(arr[i]) > abs(arr[j])))) {
            help_arr[h] = arr[j];
            j++;
        }
        else {
            help_arr[h] = arr[i];
            i++;
        }
        h++;
    }
    for (i = left; i < right + 1; i++) {
        arr[i] = help_arr[i - left];
    }
}
void insertsort(long *arr, long start, long end)
{
    long unsorted, i, elem;
    for (i = start + 1; i <= end; i++) {
        elem = arr[i];
        for (unsorted = i - 1; unsorted >= start; unsorted--) {
            if (abs(elem) < abs(arr[unsorted])) arr[unsorted + 1] = arr[unsorted];
            else break;
        }
        arr[unsorted + 1] = elem;
    }
}
void mergesort(long *arr, long left, long right)
{
    long mid;
    if ((right - left + 1) < 5) {
        insertsort(arr, left, right);
    }
    else {
        mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main(int argc, char **argv)
{
    long i, n, j;
    scanf("%ld", &n);
    long arr[n];
    for (i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    for (i = 0; i < n; i++) printf("%ld ", arr[i]);
    printf("\n");
    return 0;
}