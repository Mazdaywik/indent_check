#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < 0) {
            arr[i] = -arr[i];
        }
    }
    int* logg = (int*) malloc((n + 1) * sizeof(int));
    logg[1] = 0;
    for (int i = 2; i <= n; i++) {
        logg[i] = logg[i / 2] + 1;
    }
    int** sparce = (int**) malloc((logg[n] + 1) * sizeof(int*));
    for (int i = 0; i <= logg[n]; i++) {
        sparce[i] = (int*) malloc(n * sizeof(int)); 
    }
    for (int i = 0; i < n; i++) {
        sparce[0][i] = arr[i];
    }
    for (int i = 1; i <= logg[n]; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            sparce[i][j] = gcd(sparce[i - 1][j], sparce[i - 1][j + (1 << (i - 1))]);
        }
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        r++;
        int len = r - l;
        int lg = logg[len];
        printf("%d\n", gcd(sparce[lg][l], sparce[lg][r - (1 << lg)]));
    }
    for (int i = 0; i <= logg[n]; i++) {
        free(sparce[i]);
    }
    free(arr);
    free(sparce);
    free(logg);
    return 0;
}