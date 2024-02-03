#include <stdio.h>

void swap(int *arr, size_t a, size_t b)
{
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

int abs(int a)
{
    if (a > 0) return a;
    else return (- a);
}

void Merge(int *arr, int k, int l, int m)
{
    int size = m - k + 1;
    int t[size];
    int i = k;
    int j = l + 1;
    int h = 0;
    while (h < size) {
        if (j <= m && (i == l + 1 || abs(arr[j]) < abs(arr[i]))) {
            t[h] = arr[j];
            j++;
        } else {
            t[h] = arr[i];
            i++;
        }
        h++;
    }
    int a = k;
    for (int b = 0; b < size ; b++) {
        arr[a] = t[b];
        a++;
    }
}

void InsertSort(int *arr, int l, int h)
{
    for (int i = l; i <= h; i++) {
        int el = arr[i];
        int loc = i -1;
        while (loc >= l && abs(arr[loc]) > abs(el)) {
            arr[loc + 1] = arr[loc];
            loc--;
        }
        arr[loc + 1] = el;
    }
}

void MergeSort(int *arr, int low, int high)
{
    if ((high - low) < 5) InsertSort(arr, low, high);
    else {
        if (low < high) {
            int med = (low + high)/2;
            MergeSort(arr, low, med);
            MergeSort(arr, med + 1, high);
            Merge(arr, low, med, high);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    MergeSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
