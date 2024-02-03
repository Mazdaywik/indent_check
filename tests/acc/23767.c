#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(char *s, int *pi) {
    int i = 1, t = 0;
    pi[0] = 0;
    int nel = strlen(s);
    while (i < nel) {
        while ((t > 0) && (s[t] != s[i])) t = pi[t-1];
        if (s[t] == s[i]) t++;
        pi[i] = t;
        i++;
    }
}

int main(int argc, char *argv[]) {
    char *s = argv[1];
    int n = strlen(s);
    int *pi = (int*)malloc(n * sizeof(int));
    prefix(s, pi);
    for (int i = 1; i < n; i++) {
        int len = i + 1;
        int period = len - pi[i];
        if (len % period == 0 && period < len) {
            printf("%d %d\n", len, len / period);
        }
    }
    free(pi);
    return 0;
}