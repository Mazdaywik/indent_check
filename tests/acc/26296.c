#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pref(char *s, int s_len, int *pi) {
    int k = 0;
    pi[0] = 0;

    for (int i = 1; i < s_len; i++) {
        while (k > 0 && s[k] != s[i])
            k = pi[k - 1];
        if (s[k] == s[i])
            k++;
        pi[i] = k;
    }
}

void kmp(char *s, char *t, int s_len, int t_len, int *pi) {
    int i = 0;
    int j = 0;

    while (i < t_len) {
        if (t[i] == s[j]) {
            i++;
            j++;
            if (j == s_len) {
                printf("%d ", i - s_len);
                j = pi[j - 1];
            }
        } else {
            if (j != 0) {
                j = pi[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main(int argc, char **argv) {
    
    char *s = argv[1];
    char *t = argv[2];

    int n = strlen(s);
    int m = strlen(t);

    int *pi = (int *) malloc(n * sizeof(int));
    if (pi == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    pref(s, n, pi);
    kmp(s, t, n, m, pi);

    free(pi);

    return 0;
}