#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void Prefix(char *S, int *pi) {
    int len = strlen(S);
    pi[0] = 0;
    int t = 0;
    
    for (int i = 1; i < len; i++) {
        while (t > 0 && (S[t] != S[i])) {
            t = pi[t - 1];
        }
        if (S[t] == S[i]) {
            t++;
        }
        pi[i] = t;
    }
}

int KMPSubst(char *S, char *T) {
    int n = strlen(T);
    int m = strlen(S);
    int pi[m];
    Prefix(S, pi);
    int q = 0;

    for (int k = 0; k < n; k++) {
        while (q > 0 && (S[q] != T[k])) {
            q = pi[q - 1];
        }
        if (S[q] == T[k]) {
            q++;
        }
        if (q == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    char *S = argv[1];
    char *T = argv[2];

    if (KMPSubst(S, T)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}