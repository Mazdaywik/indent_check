#include <stdio.h>
#include <string.h>
void pref_func(char s[], int pref[], int n) 
{
    int i, t = 0;
    pref[0] = 0;
    for (i = 1; i < n; i++) {
        while ((t > 0) && (s[t] != s[i])) {
            t = pref[t - 1];
        }
        if (s[t] == s[i]) t++;
        pref[i] = t; 
    }
}
void kmp(char *s, char *t, int pref[])
{
    int q = 0, k, len_t = strlen(t), len_s = strlen(s);
    for (k = 0; k < len_t; k++) {
        while (q > 0 && s[q] != t[k]) {
            q = pref[q - 1];
        }
        if (s[q] == t[k]) q++;
        if (q == len_s) {
            printf("%d ", k - len_s + 1);
            q = 0;
            k = k - len_s + 1;
        }
    }
}
int main(int argc, char **argv)
{
    char *s = argv[1], *t = argv[2];
    int len_t = strlen(t), pref[len_t], i, j;
    pref_func(t, pref, len_t);
    kmp(s, t, pref);
    return 0;
}