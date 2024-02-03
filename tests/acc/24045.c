
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computePrefixFunction(char* s, int prefix[], int n) {
    prefix[0] = 0;
    int k = 0;
    for (int i = 1; i < n; i++) {
        while (k > 0 && s[k] != s[i]) {
            k = prefix[k - 1];
        }
        if (s[k] == s[i]) {
            k++;
        }
        prefix[i] = k;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    char* s = argv[1];
    int n = strlen(s);

    int* prefix = (int*)malloc(n * sizeof(int));
    computePrefixFunction(s, prefix, n);

    for (int i = 1; i < n; i++) {
        if (prefix[i] > 0 && (i + 1) % (i + 1 - prefix[i]) == 0) {
            printf("%d %d\n", i + 1, (i + 1) / (i + 1 - prefix[i]));
        }
    }
    free(prefix);
    return 0;
}