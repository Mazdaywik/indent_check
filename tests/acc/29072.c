#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


union Int32 {
    int x;
    unsigned char bytes[4];
};

int key(unsigned char bytes[4], int q)
{
    if(q == 3) {
        return bytes[q] ^ 128;
    }
    return bytes[q];
}


void DistributionSort(int (*key)(unsigned char bytes[4], int q), 
            size_t m, union Int32 S[], size_t n, union Int32 *D, int q)
{
    int *count = calloc(m, sizeof(int));

    for(int j = 0; j < n; j++) {
        int k = key(S[j].bytes, q);
        count[k]++;
    }

    for(int i = 1; i < m; i++) {
        count[i] += count[i - 1];
    }

    for(int j = n - 1; j >= 0; j--) {
        int k = key(S[j].bytes, q);
        int i = --count[k];
        D[i] = S[j];
    }
    free(count);
}


void RadixSort(int (*key)(unsigned char bytes[4], int q), 
            size_t m, union Int32 S[], size_t n)
{
    union Int32 *D = calloc(n, sizeof(union Int32));
    for(int i = 0; i <= 3; i++) {
        DistributionSort(key, m, S, n, D, i);
        memcpy(S, D, n * sizeof(union Int32));
    }
    free(D);
}


int main() {
    int n;
    scanf("%d", &n);
    union Int32 S[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &S[i].x);
    }

    RadixSort(key, 256, S, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", S[i].x);
    }

    return 0;
}