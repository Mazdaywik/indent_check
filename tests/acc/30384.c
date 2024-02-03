#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void kmp(char *s, char *t, int *p) {
    int i = 0, j = 0, n = strlen(s), m = strlen(t);
    while (i < m) {
        if (s[j] == t[i]) {
            i++;
            j++;
        }
        if (j == n) {
            printf("%d ", i - j);
            j = p[j - 1];
        } else if (i < m && s[j] != t[i]) {
            if (j != 0) {
                j = p[j - 1];
            } else {
                i++;
            }
        }
    }
}

void prefix(char *s, int *p) {
    int i = 1, j = 0, n = strlen(s);
    while (i < n) {
        if (s[i] == s[j]) {
            j++;
            p[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = p[j - 1];
            } else {
                p[i] = 0;
                i++;
            }
        }
    }
}

int main(int argc, char **argv) {
    char *s = argv[1], *t = argv[2];
    int n = strlen(s), m = strlen(t);
    int *p = (int *) malloc(n * sizeof(int));
    memset(p, 0, n * sizeof(int));
    prefix(s, p);
    kmp(s, t, p);
    free(p);
    return 0;
}
