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
void is_prefix(char *s, char *t, int pref[])
{
    int i, j = 0, len_t = strlen(t);
    for (i = 0; i < len_t; i++) {
        while (t[i] != s[j]) {
            if (j > 0) j = pref[j - 1];
            else break;
        }
        if (t[i] == s[j]) j++;
        if (j == 0) {
            printf("no");
            return;
        }
    }
    printf("yes");
}
int main(int argc, char **argv)
{
    char *s = argv[1], *t = argv[2];
    int len_s = strlen(s), pref[len_s];
    pref_func(s, pref, len_s);
    is_prefix(s, t, pref);
    return 0;
}