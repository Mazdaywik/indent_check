#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computePrefixFunction(char* s, int* pi) {
    int len = strlen(s);
    pi[0] = 0;
    for (int i = 1; i < len; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
}

void findPeriodicPrefixes(char* s) {
    int len = strlen(s);
    int* pi = (int*)malloc(len * sizeof(int));
    
    computePrefixFunction(s, pi);
    
    for (int i = 1; i < len; i++) {
        if (pi[i] > 0 && (i + 1) % (i + 1 - pi[i]) == 0) {
            printf("%d %d\n", i + 1, (i + 1) / (i + 1 - pi[i]));
        }
    }
    
    free(pi);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("%s", argv[0]);
        return 1;
    }
    findPeriodicPrefixes(argv[1]);
    return 0;
}