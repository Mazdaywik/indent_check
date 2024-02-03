#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void insert_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && abs(a[j]) > abs(key)) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void merge(int a[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (abs(left[i]) <= abs(right[j])) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int n) {
    if (n <= 4) {
        insert_sort(a, n);
    } else {
        int mid = n / 2;
        int left[mid];
        int right[n - mid];

        for (int i = 0; i < mid; i++) {
            left[i] = a[i];
        }

        for (int i = mid; i < n; i++) {
            right[i - mid] = a[i];
        }

        mergeSort(left, mid);
        mergeSort(right, n - mid);
        merge(a, left, mid, right, n - mid);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if(n >= 5){ 
       
        mergeSort(a, n);
        
    }
    else{
        insert_sort( a, n);
    }

    
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    

    return 0;
}