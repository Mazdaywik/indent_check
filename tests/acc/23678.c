#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(char *str, size_t len, int *p_arr)
{
    int t = 0;
    for (int i = 1; i < len; i++)
    {

        while (t > 0 && str[t] != str[i])
        {
            t = p_arr[t - 1];
        }

        if (str[t] == str[i])
            t++;

        p_arr[i] = t;
    }
}

void kmp(char *s, size_t len_s, char *t, size_t len_t, int *p_arr)
{
    int i = 0, j = 0;

    while (i < len_t)
    {
        if (t[i] == s[j])
        {
            i++;
            j++;
            if (j == len_s)
            {
                i--;
                printf("%ld ", i - len_s + 1);
                i = i - len_s +2;
                j = 0;
            }
        }
        else
        {
            if (j > 0)
                j = p_arr[j - 1];
            else
                i++;
        }
    }
}

int main(int argc, char **argv)
{
    char *s = argv[1];
    char *t = argv[2];

    size_t len_t = strlen(t);
    size_t len_s = strlen(s);

    int p_arr[len_s];
    p_arr[0] = 0;

    prefix(s, len_s, p_arr);
    kmp(s, len_s, t, len_t, p_arr);

    return 0;
}