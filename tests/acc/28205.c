#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computePrefixFunction(char* s, int len, int* pi) {
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < len; i++) {
        while (k > 0 && s[k] != s[i]) {
            k = pi[k - 1];
        }
        if (s[k] == s[i]) {
            k++;
        }
        pi[i] = k;
    }
}

void findPeriodicPrefixes(char* s) {
    int len = strlen(s);
    int pi[len];

    computePrefixFunction(s, len, pi);

    for (int i = 1; i < len; i++) {
        if (pi[i] > 0 && (i + 1) % (i + 1 - pi[i]) == 0) {
            printf("%d %d\n", i + 1, (i + 1) / (i + 1 - pi[i]));
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./prefixes string\n");
        return 1;
    }

    findPeriodicPrefixes(argv[1]);
    return 0;
}
