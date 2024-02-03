#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  

union Int32 {
    int x;
    unsigned char bytes[4];
};


void countSort(union Int32 arr[], int n, int exp) {
    union Int32 output[n]; 
    int i, count[256] = {0};

 
    for (i = 0; i < n; i++)
        count[arr[i].bytes[exp]]++;


    for (i = 1; i < 256; i++)
        count[i] += count[i - 1];


    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i].bytes[exp]] - 1] = arr[i];
        count[arr[i].bytes[exp]]--;
    }

   
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(union Int32 arr[], int n) {
    for (int exp = 0; exp < 4; exp++)
        countSort(arr, n, exp);
}

int main() {
    int n;
    scanf("%d", &n);

    union Int32 *arr = (union Int32 *)malloc(n * sizeof(union Int32));


    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].x);
        arr[i].x += INT_MAX; 
    }

    radixSort(arr, n);


    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].x - INT_MAX);  
    }
    printf("\n");

    free(arr);
    return 0;
}