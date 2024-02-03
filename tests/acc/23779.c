#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Prefix(const char *S, int *pi) {
    int m = strlen(S);
    pi[0] = 0;
    int k = 0;
    for (int q = 1; q < m; q++) {
        while (k > 0 && S[k] != S[q])
            k = pi[k - 1];
        if (S[k] == S[q])
            k++;
        pi[q] = k;
    }
}

void KMP(const char *S, const char *T) {
    int m = strlen(S);
    int n = strlen(T);
    int *pi = (int *)malloc(m * sizeof(int));
    Prefix(S, pi);
    int q = 0;
    for (int k = 0; k < n; k++) {
        while (q > 0 && S[q] != T[k])
            q = pi[q - 1];
        if (S[q] == T[k])
            q++;
        if (q == m) {
            printf("%d ", k - m + 1);
            q = pi[q - 1];
        }
    }

    free(pi);
}

int main(int argc, char *argv[]) {
    KMP(argv[1], argv[2]);
    return 0;
}