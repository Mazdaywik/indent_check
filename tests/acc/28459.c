#include <stdio.h>
#include <math.h>

#define MAX_SIZE 1048576
#define MAX_K 20

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int sparseTable[MAX_SIZE][MAX_K];

void buildSparseTable(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        sparseTable[i][0] = arr[i];
    }
    int m = log2(n) + 1;
    for (int j = 1; j < m; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            sparseTable[i][j] = gcd(sparseTable[i][j - 1], sparseTable[i + (1 << (j - 1))][j - 1]);
        }
    }
}




int query(int l, int r) {
    int j = log2(r - l + 1);
    return gcd(sparseTable[l][j], sparseTable[r - (1 << j) + 1][j]);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    buildSparseTable(arr, n);
    
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        int result = query(l, r);

        if (result < 0)
            result *= -1;
        printf("%d\n", result);
    }
    return 0;
}
