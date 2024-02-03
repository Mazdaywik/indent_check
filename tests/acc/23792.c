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

int new_kmp(char *s, size_t len_s, char *t, size_t len_t, int *p_arr)
{
    int i = 0, j = 0;

    while (i < len_t)
    {
        if (t[i] == s[j])
        {
            i++;
            j++;
            if (j == len_s)
                j = p_arr[j - 1];
        }
        else
        {
            if(j == 0)
                return 0;
            if (j > 0)
                j = p_arr[j - 1];
            else
                i++;
        }
    }
    
    return 1;
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
    int res = new_kmp(s, len_s, t, len_t, p_arr);
    if(res == 1)
        printf("yes");
    else
        printf("no");

    return 0;
}