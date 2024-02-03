#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void csort(char *src, char *dest)
{
    long long ind = 0, n_char = 0, n = 0;
    char *lst[200];
    lst[ind] = (char*) malloc(200 * sizeof(char));
    char ch = src[n];
    while (ch != '\0')
    {
        lst[ind][n_char] = ch;
        n_char++;
        n++;
        ch = src[n];
        if (ch == ' ')
        {
            lst[ind][n_char] = '\0';
            n_char = 0;
            ind++;
            lst[ind] = (char*) malloc(200 * sizeof(char));
            while (ch == ' ')
            {
                ch = src[n];
                n++;
            }
            n--;
        }
    }
    lst[ind][n_char] = '\0';
    long long strs_len[ind+1];
    long long sortlist[ind+1];
    for (long long i = 0; i <= ind; i++)
    {
        strs_len[i] = strlen(lst[i]);
        sortlist[i] = 0;
    }
    for (long long i = 0; i <= ind; i++)
    {
        for (long long j = 0; j <= ind; j++)
        {
            if (strs_len[i] > strs_len[j])
            {
                sortlist[j]++;
            }
        }
    }
    long long j;
    n = 0;
    long long max_ind = 0, max_val = 0, val;
    for (long long i = 0; i <= ind; i++)
    {
        for (long long j = 0; j <= ind; j++)
        {
            if (sortlist[j] > max_val)
            {
                max_ind = j;
                max_val = sortlist[j];
            }
        }
        j = 0;
        while (lst[max_ind][j] != '\0')
        {
            dest[n] = lst[max_ind][j];
            n++;
            j++;
        }
        dest[n] = ' ';
        n++;
        sortlist[max_ind] = -1;
        max_val = -1;
    }
    dest[n-1] = '\0';
    for (long long i = 0; i <= ind; i++)
    {
        free(lst[i]);
    }
    printf("%s", dest);
}


int main() 
{
    char ch;
    char str[1000], sorted_str[1000];
    long long ind = 0;
    scanf("%c", &ch);
    while (ch != '\n')
    {
        str[ind] = ch;
        ind++;
        scanf("%c", &ch);
    }
    str[ind] = '\0';

    csort(str, sorted_str);


    return 0;
}


