#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long KMP_Subst(char *s, char *t, long *prefix, long len_S, long len_T)
{
    long q = 0, k = 0;
    while (k < len_T)
    {
        while (q > 0 & s[q] != t[k])
            q = prefix[q - 1];
        if (s[q] == t[k])
            q++;
        if (q == 0)
        {
            k = k - len_S + 3;
            return k;
        }
        k++;
    }
    return 0;
}

long *prefix_func(char *s, int len_s)
{
    long *prefix = malloc(2 * (len_s) * sizeof(long));
    prefix[0] = 0;
    long t = 0;

    for (long i = 1; i < len_s; i++)
    {
        while (t > 0 & s[t] != s[i])
        {
            t = prefix[t - 1];
        }
        if (s[t] == s[i])
            t++;
        prefix[i] = t;
    }
    return prefix;
}

int main(int argc, char **argv)
{
    char *s = argv[1];
    char *r = argv[2];
    long len_s = strlen(s);
    long len_r = strlen(r);
    long *prefix = prefix_func(s, len_s);
    if (KMP_Subst(s, r, prefix, len_s, len_r) == 0)
        printf("yes\n");
    else
        printf("no\n");
    free(prefix);
    return 0;
}
