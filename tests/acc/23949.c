#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void Delta1(char *S, int size, int *delta1) {
    for (int a = 0; a < 126; a++)
        delta1[a] = size;

    for (int j = 0; j < size; j++)
        delta1[(int)S[j]] = size - j - 1;
}

void Suffix(char *S, int *sigma) {
    int lenS = strlen(S);
    int t = lenS - 1;
    sigma[lenS - 1] = t;

    for (int i = lenS - 2; i >= 0; i--) {
        while (t < lenS - 1 && S[t] != S[i])
            t = sigma[t + 1];

        if (S[t] == S[i])
            t--;

        sigma[i] = t;
    }
}

void Delta2(char *S, int *delta2) {
    int lenS = strlen(S);
    int *sigma = (int *)malloc(lenS * sizeof(int));
    Suffix(S, sigma);
    int t = sigma[0];
    for (int i = 0; i < lenS; i++) {
        while (t < i)
            t = sigma[t + 1];

        delta2[i] = lenS - i + t;
    }

    for (int i = 0; i < lenS - 1; i++) {
        t = i;
        while (t < lenS - 1) {
            t = sigma[t + 1];
            if (S[i] != S[t])
                delta2[t] = lenS - i - 1;
        }
    }

    free(sigma);
}

void BMSubst(char *S, char *T) {
    int lenS = strlen(S), lenT = strlen(T);
    int delta1[126], delta2[lenS];

    Delta1(S, lenS, delta1);
    Delta2(S, delta2);

    int k = lenS - 1;
    while (k < lenT) {
        int i = lenS - 1;
        while (i >= 0 && T[k] == S[i]) {
            i--;
            k--;
        }

        if (i < 0) {
            printf("%d ", k + 1);
            k += lenS + 1;
        } else {
            k += max(delta1[(int)T[k]], delta2[i]);
        }
    }
}


int main(int argc, char *argv[]) {
    BMSubst(argv[1], argv[2]);
    return 0;
}