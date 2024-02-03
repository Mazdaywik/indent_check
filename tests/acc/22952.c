#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *a, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int elem = a[i];
        int loc = i - 1;
        while (loc >= left && abs(a[loc]) > abs(elem)) {
            a[loc + 1] = a[loc];
            loc--;
        }
        a[loc + 1] = elem;
    }
}

void merge(int a[], int l, int m, int r) 
{
    int n1 = m - l + 1, n2 = r - m, L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l+i];
    for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (abs(L[i]) <= abs(R[j])) {
            a[l] = L[i];
            i++;
        }
        else {
            a[l] = R[j];
            j++;
        }
        l++;
    }
    for (; i < n1; i++, l++) a[l] = L[i];
    for (; j < n2; j++, l++) a[l] = R[j];
}
void mergeSort(int a[], int left, int right) 
{
    if (right - left < 5) InsertSort(a, left, right);
    else if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i<n; i++) scanf("%d", &a[i]);
    int left = 0, right = n - 1;
    mergeSort(a, left, right);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}