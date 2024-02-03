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
int main(int argc, char **argv)
{
    char *s = argv[1];
    int len = strlen(s), pref[len], i, j;
    pref_func(s, pref, len);
    for (i = 1; i <= len; i++) {
        j = i - pref[i - 1];
        if ((i % j == 0) && (i != j)) {
            printf("%d %d\n", i, i / j);
        }
    }
    return 0;
}