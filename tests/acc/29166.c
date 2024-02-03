#include <stdio.h>
#include <stdlib.h>

int *array;

int compare(unsigned long i, unsigned long j) {
    if (array[i] == array[j]) return 0;
    return (array[i] < array[j]) ? -1 : 1;
}

void swap(unsigned long i, unsigned long j) {
    int t = array[i];
    array[i] = array[j];
    array[j] = t;
}

void generateFibonacci(int a[], int nel, int *size) {
    int prevFib = 0;
    int currentFib = 1;
    int i = 0;
    
    while (currentFib <= nel) { 
        a[i++] = currentFib;
        int nextFib = prevFib + currentFib;
        prevFib = currentFib;
        currentFib = nextFib;
    }
    *size = i; 
}

void shellsort(unsigned long n, int (*compare)(unsigned long, unsigned long), void (*swap)(unsigned long, unsigned long)) {
    int a[30];
    int size;
    
    generateFibonacci(a, n, &size);
    
    for (int k = size - 1; k >= 0; k--) {
        int d = a[k];
        
        for (unsigned long i = d; i < n; i++) {
            for (unsigned long j = i; j >= d && compare(j-d, j) > 0; j -= d) {
                swap(j-d, j);
            }
        }
    }
}

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    array = (int *)malloc(n * sizeof(int));
    if (!array) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    shellsort(n, compare, swap);
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}