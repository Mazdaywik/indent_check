#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(char *s, int *pi, size_t len)
{
    int t = 0;
    int i = 1;
    while (i < len) {
        while (t > 0 && s[t] != s[i])
            t = pi[t - 1];
        if (s[t] == s[i])
            t++;
        pi[i] = t;
        i++;
    }
}

void KMPSubst(char *s, char *t, int *pi, size_t len)
{
    prefix(s, pi, len);
    int q = 0;
    int k = 0;
    while (k < strlen(t)) {
        while (q > 0 && s[q] != t[k]) {
            q = pi[q - 1];
        }
        if (s[q] == t[k]) {
            q++;
        }
        if (q == len) {
            printf("%ld\n", k - len + 1);
        }
        k++;
    }
}

int main(int argc, char **argv)
{
    char *s = argv[1];
    char *t = argv[2];
    
    size_t lenght = strlen(s);
    
    if (lenght > strlen(t)) {
        printf("\n");
        return 0;
    }
        
    int *pi = (int*) calloc(lenght, sizeof(int));
    for (int i = 0; i < lenght; i++) pi[i] = 0;
    
    KMPSubst(s, t, pi, lenght);
    free(pi);
    return 0;
}
