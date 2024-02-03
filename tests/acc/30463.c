#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pref(char *s, int* prefixes, int length, int t, int i)
{
    if (i < length)
    {
        while (t > 0 && s[t] != s[i])
            {
                t = prefixes[t - 1];
            }
            
            if (s[t] == s[i])
            {
                t++;
            }

            prefixes[i] = t;

            int k = i + 1;

            if (prefixes[i] > 0 && (k % (k - prefixes[i])) == 0)
            {
                printf("%d %d\n", k, k / (k - prefixes[i]));
            }

        pref(s, prefixes, length, t, ++i);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    char *s = argv[1];
    int length = strlen(s);
    int* prefixes = (int*)malloc(sizeof(int) * length);
    prefixes[0] = 0;

    pref(s, prefixes, length, 0, 1);

    free(prefixes);

    return 0;
}
