#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char *s = argv[1];

    int n = strlen(s);
    int *pi = malloc(sizeof(int) * n);
    pi[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
    
    for (int i = 1; i <= n; i++) {
        int j = i - pi[i - 1];
        if (i % j == 0 && i != j) {
            printf("%d %d\n", i, i / j);
        }
    }
    
    free(pi);

    return 0;
}