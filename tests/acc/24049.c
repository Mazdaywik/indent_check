
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computePrefixFunction(char* s, int prefix[], int n) {
    prefix[0] = 0;
    int k = 0;
    for (int i = 1; i < n; i++) {
        while (k > 0 && s[k] != s[i]) {
            k = prefix[k - 1];
        }
        if (s[k] == s[i]) {
            k++;
        }
        prefix[i] = k;
    }
}

void kmpSearchAll(char* S, char* T) {
    int m = strlen(S);
    int n = strlen(T);

    int* prefix = (int*)malloc(m * sizeof(int));
    computePrefixFunction(S, prefix, m);

    int q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && S[q] != T[i]) {
            q = prefix[q - 1];
        }
        if (S[q] == T[i]) {
            q++;
        }
        if (q == m) {
            printf("%d\n", i - m + 1);
            q = prefix[q - 1];
        }
    }
    free(prefix);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }

    char* S = argv[1];
    char* T = argv[2];

    kmpSearchAll(S, T);

    return 0;
}
