#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int key(char element) {
    return element - 'a';
}

void DistributionSort(char *S, int n, int m) {
    int *count = (int*)calloc(m, sizeof(int));
    
    for (int j = 0; j < n; j++) {
        count[key(S[j])]++;
    }
    
    for (int i = 1; i < m; i++) {
        count[i] += count[i - 1];
    }
    
    char *D = (char*)malloc(n * sizeof(char));
    
    for (int j = n - 1; j >= 0; j--) {
        int k = key(S[j]);
        D[--count[k]] = S[j];
    }
    
    memcpy(S, D, n * sizeof(char));
    S[n] = '\0';
    
    free(D);
    free(count);
}

int main() {
    char S[1000001];
    fgets(S, sizeof(S), stdin);
    
    int n = strlen(S);
    if (S[n-1] == '\n') {
        S[--n] = 0;
    } 
    int m = 26;
    
    DistributionSort(S, n, m);
    
    printf("%s", S);
    
    return 0;
}