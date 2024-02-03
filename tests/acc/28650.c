#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void suffix(char *S, int *sigma) {
    int len = strlen(S);
    sigma[len - 1] = len - 1;
    int t = len - 1;
    for (int i = len - 2; i >= 0; --i) {
        while (t < len - 1 && S[i] != S[t]) {
            t = sigma[t + 1];
        }
        if (S[i] == S[t]) {
            t--;
        }
        sigma[i] = t;
    }
}

void delta1(char *S, int *del1, int size) {
    int len = strlen(S);
    for (int a = 0; a < size; ++a) {
        del1[a] = len;
    }
    for (int j = 0; j < len; ++j) {
        del1[S[j]] = len - j - 1;
    }
}

void delta2(char *S, int *del2, int *sigma) {
    int len = strlen(S);
    suffix(S, sigma);

    int i, t = sigma[0];
    for (i = 0; i < len; ++i) {
        while (t < i) {
            t = sigma[t + 1];
        }
        del2[i] = -i + t + len;
    }

    for (i = 0; i < len - 1; ++i) {
        t = i;
        while (t < len - 1) {
            t = sigma[t + 1];
            if (S[i] != S[t]) {
                del2[t] = -(i + 1) + len;
            }
        }
    }
}

void BMSubst(char *S, int size, char *T) {
    int len_S = strlen(S);
    int len_T = strlen(T);
    int del1[size];
    int del2[len_S];
    int sigma[len_S];
    delta1(S, del1, size);
    delta2(S, del2, sigma);

    int k = len_S - 1;
    while (k < len_T) {
        int i = len_S - 1;
        while (T[k] == S[i]) {
            if (i == 0) {
                printf("%d ", k);
                break;
            }
            i--;
            k--;
        }
        k += fmax(del1[T[k]], del2[i]);
    }
    k = len_T;
}

int main(int argc, char **argv) {
    char *S = argv[1];
    char *T = argv[2];
    int size = 256;
    BMSubst(S, size, T);

    return 0;
}