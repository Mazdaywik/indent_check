#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void kadane(long double *arr, int n) {
    int l = 0, r = 0;
    long double maxcomp = arr[0];
    long double comp = 1;
    int start = 0;
    int i = 0;
    
    while (i < n) {
        comp *= arr[i];
        if (comp > maxcomp) {
            maxcomp = comp;
            l = start;
            r = i;
        }
        
        i++;
        
        if (comp < 1) {
            comp = 1;
            start = i;
        }
    }
    printf("%d %d", l, r);
}

int main() {
    int n;
    scanf("%d", &n);
    
    long double *arr = (long double *)malloc(n * sizeof(long double));

    for (int i = 0; i < n; i++) {
        long double a, b;
        char s;
        scanf("%Lf%c%Lf", &a, &s, &b);
        arr[i] = a/b;
    }

    kadane(arr, n);

    free(arr);
    return 0;
}