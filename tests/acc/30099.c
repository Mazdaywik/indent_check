//источник: полностью с презентации №2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int *Suffix(char *S) {
    int len_s = strlen(S);
    int t = len_s - 1;
    int *suffix = malloc(len_s * sizeof(int));
    suffix[t] = t;
    int i = len_s - 2;
    while (i >= 0) {
        while ((t < len_s - 1) && (S[t] != S[i]))
            t = suffix[t + 1];
        if (S[t] == S[i])
            t -= 1;
        suffix[i] = t;
        i -= 1;
    }
    return suffix;
}

int *Delta2(char *S) {
    int len_s = strlen(S);
    int *delta2 = malloc(len_s * sizeof(int));
    int *suffix = Suffix(S);
    int i = 0;
    int t = suffix[0];
    while (i < len_s) {
        while (t < i)
            t = suffix[t + 1];
        delta2[i] = (-i + t + len_s);
        i += 1;
    }
    i = 0;
    while (i < len_s - 1) {
        t = i;
        while (t < len_s - 1) {
            t = suffix[t + 1];
            if (S[i] != S[t])
                delta2[t] = (-(i + 1) + len_s);
        }
        i += 1;
    }
    free(suffix);
    return delta2;
}


int *Delta1(char *S, int size) {
    int *delta1 = malloc((size_t)size * sizeof(int));
    int a = 0;
    int len_s = strlen(S);
    while (a < size) {
        delta1[a] = len_s;
        a += 1;
    }
    int j = 0;
    while (j < len_s) {
        delta1[S[j] - 33] = (len_s - j - 1);
        j += 1;
    }
    return delta1;
}

void BMSubst(char *S, int size, char *T) {
    int len_s = strlen(S);
    int *delta1 = Delta1(S, size);
    int *delta2 = Delta2(S);
    int k = len_s - 1;
    int i;
    while (k < strlen(T)) {
        i = len_s - 1;
        while (T[k] == S[i]) {
            if (i == 0) {
                printf("%d ", k);
                break;
            }
            i -= 1;
            k -= 1;
        }
        k += max(delta1[T[k] - 33], delta2[i]);
    }
    free(delta1);
    free(delta2);
}

int main(int argc, char **argv) {
    BMSubst(argv[1], 94, argv[2]);
    return 0;
}