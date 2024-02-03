#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void KMPSearch(char *s, char *t) {
    int lenght_s = strlen(s);
    int lenght_t = strlen(t);
    int pi[lenght_s], pi_t = 0;
    pi[0] = 0;
    for (int i = 1; i < lenght_s; i++) {
        while (pi_t > 0 && s[i] != s[pi_t]) {
            pi_t = pi[pi_t - 1];
        }
        if (s[i] == s[pi_t]) {
            pi_t++;
        }
        pi[i] = pi_t;
    }
    int q = 0, k = 0;
    while (k < lenght_t) {
        while (q > 0 && s[q] != t[k])
            q = pi[q - 1];
        if (s[q] == t[k])
            q++;
        if (q == lenght_s)
            printf("%d\n", k - lenght_s + 1);
        k++;
    }
}

int main(int argc, char *argv[]) {
    char *S = argv[1];
    char *T = argv[2];
    KMPSearch(S, T);
    return 0;
}