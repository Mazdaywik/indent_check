#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void KKK(const char *s, int len, int *pi) {
    int k = 0;
    pi[0] = 0;

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

int Prefixes(const char *S, const char *T) {
    int lenS = strlen(S);
    int lenT = strlen(T);
    int pi[lenS];
    KKK(S, lenS, pi);
    int count = 0;
    for (int i = 0; i < lenT; i++) {
        while (count > 0 && S[count] != T[i]) {
            count = pi[count - 1];
        }
        if (S[count] == T[i]) {
            count++;
            if (count == lenS) {
                count = pi[count - 1];
            }
        } else {
            return 0; 
        }
    }

    return 1; 
}

int main(int argc, char **argv) {
    printf("%s\n", Prefixes(argv[1], argv[2]) ? "yes" : "no");
    return 0;
}