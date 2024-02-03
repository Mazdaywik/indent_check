#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}

int* Delta1(char* S, int size) {
    size_t len = strlen(S);
    int* delta1;
    delta1 = (int*) malloc(size * sizeof(int));
    int a = 0;
    while (a < size) {
        delta1[a] = len;
        ++a;
    }
    int j = 0;
    while (j < len) {
        delta1[S[j] - 33] = len - j - 1;
        ++j;
    }
    return delta1;
}

int* Suffix(char* S) {
    size_t len = strlen(S);
    int* sigma;
    sigma = (int*) malloc(len * sizeof(int));
    sigma[len-1] = len - 1;
    int t = len - 1;
    int i = len - 2;
    while (i >= 0) {
        while ((t < (len - 1)) && S[t] != S[i]) {
            t = sigma[t+1];
        }
        if (S[t] == S[i]) --t;
        sigma[i] = t;
        --i;
    }
    return sigma;
}

int* Delta2(char* S) {
    size_t len = strlen(S);
    int* delta2;
    delta2 = (int*) malloc(len * sizeof(int));
    int* sigma = Suffix(S);
    int i = 0, t = sigma[0];
    while (i < len) {
        while (t < i) {
            t = sigma[t+1];
        }
        delta2[i] = -i + t + len;
        ++i;
    }
    i = 0;
    while (i < (len - 1)) {
        t =  i;
        while (t < (len - 1)) {
            t = sigma[t+1];
            if (S[i] != S[t]) {
                delta2[t] = -(i + 1) + len;
            }
        }
        ++i;
    }
    free(sigma);
    return delta2;
}

void BMSSubst(char* S, int size, char* T) {
    size_t len_S = strlen(S);
    size_t len_T = strlen(T);
    int* delta1 = Delta1(S, size);
    int* delta2 = Delta2(S);
    int k = len_S - 1;
    while (k < len_T) {
        int i = len_S - 1;
        while (T[k] == S[i]) {
            if (i == 0) {
                printf("%d ", k);
                break;
            }
            --i; --k;
        }
        k = k + max(delta1[T[k]-33], delta2[i]);
    }
    free(delta1);
    free(delta2);
    printf("\n");
}

int main(int argc, char** argv) {
    char* S = argv[1];
    char* T = argv[2];
    int size = 126 - 33 + 1;
    BMSSubst(S, size, T);
    return 0;
}