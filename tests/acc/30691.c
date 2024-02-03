#include <stdio.h>
#include <stdlib.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

void radixSort(union Int32 *d, int n) {
    union Int32 *D = malloc(n * sizeof(union Int32));
    int count[256];
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 256; i++) {
            count[i] = 0;
        }
        int u;
        for (int i = 0; i < n; i++) {
            u = d[i].bytes[k];
            if (k == 3) u ^= 128;
            count[u]++;
        }
        for (int i = 1; i < 256; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            u = d[i].bytes[k];
            if (k == 3) u ^= 128;
            D[count[u] - 1] = d[i];
            count[u]--;
        }
        for (int i = 0; i < n; i++) {
            d[i] = D[i];
        }
    }
    free(D);
}

int main() {
    int n;
    scanf("%d", &n);
    union Int32 p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &(p[i].x));
    }
    radixSort(p, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i].x);
    }
    return 0;
}