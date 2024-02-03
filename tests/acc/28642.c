#include <stdio.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

int key(union Int32 *nums[], int c, int i) {
    int Key = (*nums)[i].bytes[c];
    if (c == 3)
        Key ^= 128;
    return Key;
}

void DistributionSort(union Int32 *arr, int c, int n, int base) {
    int count[base];
    union Int32 D[n];
    for (int i = 0; i < base; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++) {
        int k = key(&arr, c, i);
        count[k]++;
    }
    for (int  i = 1; i < base; i++)
        count[i] += count[i - 1];
    for (int j = n-1; j >= 0; j--) {
        int k = key(&arr, c, j);
        count[k] -= 1;
        D[count[k]] = arr[j];
    }
    for (int i = 0; i < n; i++)
        arr[i] = D[i];
}

void radixsort(union Int32 *mas, int c, int n, int base) {
    for (int i = 0; i < c; i++)
        DistributionSort(mas, i, n, base);
}


int main() {
    int n;
    scanf("%i", &n);
    union Int32 arr[n];
    for (int i = 0; i < n; i++)
        scanf("%i", &arr[i].x);
    radixsort(arr, 4, n, 256);
    for (int i = 0; i < n; i++)
        printf("%i ", arr[i].x);
    return 0;
}