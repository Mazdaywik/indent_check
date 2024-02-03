#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void insert_sort(int *arr, int n) {
    int j, elem;
    for(int i = 0; i < n; i++) {
        elem = arr[i];
        for(j = i - 1; (abs(arr[j]) > abs(elem)) && (j >= 0); j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = elem;
    }
}

void merge(int *arr, int l, int m, int r) {
    int t[r - l + 1];
    int i = l;
    int j = m + 1, x;
    for(x = 0; x < r - l + 1; x++){
        if (j <= r && (i == m + 1 || abs(arr[j]) < abs(arr[i]))){
            t[x] = arr[j];
            j++;
        }else{
            t[x] = arr[i];
            i++;
        }
    }
    for(x--; x >= 0 ; x--)
        arr[x + l] = t[x];
}

void merge_sort(int *arr, int low, int high) {
    if (high - low <= 5)
        insert_sort(arr + low, high - low + 1);
    else{
        int med = (low + high) / 2;
        merge_sort(arr, low, med);
        merge_sort(arr, med + 1, high);
        merge(arr, low, med, high);
    }

}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);
    merge_sort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
