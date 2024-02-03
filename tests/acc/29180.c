#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPrefix(char *pattern, char *text) {
    int patternLen = strlen(pattern);
    int textLen = strlen(text);
    int *pi = (int *)malloc(patternLen * sizeof(int));

    int k = 0;
    pi[0] = 0;
    int b = 0;

    for (int i = 1; i < patternLen; i++) {
        while (k > 0 && pattern[k] != pattern[i])
            k = pi[k - 1];

        if (pattern[k] == pattern[i])
            k++;

        pi[i] = k;
    }

    for (int i = 0; i < textLen; i++) {
        while (b > 0 && pattern[b] != text[i])
            b = pi[b - 1];

        if (pattern[b] == text[i])
            b++;

        if (b == 0) {
            free(pi);
            return 0;
        }

        if (b == patternLen)
            b = pi[b - 1];
    }

    free(pi);
    return 1;
}

int main(int argc, char *argv[]) {
    if (isPrefix(argv[1], argv[2])) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}