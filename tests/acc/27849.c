#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertionSort(int* arr, int n)
{
  int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
      
        while (j >= 0 && abs(arr[j]) > abs(key)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int* arr, int l, int m, int r)
{
  int i, j, k;
  int n = r - l + 1;

  int* L = malloc(n * sizeof(int));
    i = l;
    j = m + 1;
    k = 0;
    while (i <= m && j <= r) {
        if (abs(arr[i]) <= abs(arr[j])) {
            L[k] = arr[i];
            i++;
        }
        else {
            L[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= m) {
        L[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r) {
        L[k] = arr[j];
        j++;
        k++;
    }

    for (i=l; i<=r; i++) {
        arr[i] = L[i-l];
    }

    free(L);
}
void mergeSort(int* arr, int l, int r)
{
    if (r > l) {
        int m = l + (r - l) / 2;
        if (r - l > 4) { // <---- 
          mergeSort(arr, l, m);
          mergeSort(arr, m + 1, r);
          merge(arr, l, m, r);
        }
      else {
        insertionSort(&arr[l], r-l+1);
      }
    }
    
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    if (n > 0) {
      mergeSort(arr, 0, n-1); 
    }
  
    for (int i = 0; i<n; i++) {
       printf("%d ", arr[i]);
    }
  
    free(arr);
  return 0;
}