#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calcpref(char *S, int *arr) {
    int length = strlen(S);
    arr[0] = 0;
    for (int q = 0, j = 1; j < length; j++) {
        while (q > 0 && S[j] != S[q])
            q = arr[q - 1];
        if (S[j] == S[q])
            q++;
        arr[j] = q;
    }
}

void KMPsubst(char *T, char *S, int *arr) { 
    int lengthT = strlen(T);
    int lengthS = strlen(S);
    int t = 0;
    for (int h = 0; h < lengthT; h++) {
        while (t > 0 && T[h] != S[t])
            t = arr[t - 1];
        if (T[h] == S[t])
            t++;
        if (t == lengthS) {
            printf("%d\n", h - t + 1);
            t = arr[t - 1]; 
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "%s\n", argv[0]);
        return 1;
    }
    char *S = argv[1];
    char *T = argv[2];
    int *arr = (int *)malloc((strlen(S) + 1) * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "\n");
        return 1;
    }
    calcpref(S, arr);
    KMPsubst(T, S, arr);
    free(arr);
    return 0;
}