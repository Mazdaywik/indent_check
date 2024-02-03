#include <stdio.h>
#include <stdlib.h>
#include<string.h>


void suf_func(char* s, int len, int* suf) 
{
    int t = len - 1;
    suf[len - 1] = t;
    for (int i = len - 2; i >= 0; --i) 
    {
        while (t < len - 1 & s[t] != s[i]) 
            t = suf[t + 1];

        if (s[t] == s[i]) t--;
        suf[i] = t;
    }
}

void delta1(char* s, int len, int* ans, int size) 
{
    for (int a = 0; a < size; a++) 
        ans[a] = len;

    for (int i = 0; i < len; i++) 
        ans[s[i]-33] = len - i - 1;
}


void delta2(char* s, int len, int* ans, int* suff) 
{
    suf_func(s, len, suff);
    int t = suff[0];
    for (int i = 0; i < len; i++) 
    {
        while (t < i) 
            t = suff[t + 1];
        ans[i] = -i + t + len;
        // printf("%d %d\n", i, ans[i]);
    }
    for (int i = 0; i < len - 1; i++) 
    {
        t = i;
        while (t < len - 1) 
        {
            t = suff[t + 1];
            if (s[i] != s[t]) 
                ans[t] = -i - 1 + len;
                // printf("%d %d\n", t, ans[t]);

        }
    }
}

void BMSubst(char *s, char *r, int len_s, int len_r)
{
    // printf("%d, %d\n", len_s, len_r);
    int size = (126 - 33 + 1);
    int delt1[size], delt2[len_s], suff[len_s];
    suf_func(s, len_s, suff);
    delta1(s, len_s, delt1, size);
    // for (int i = 0; i<size; i++)
    // {
    //     printf("%d ", delt1[i]);
    // }
    // printf("\n");
    delta2(s, len_s, delt2, suff);
    // for (int i = 0; i<len_s; i++)
    // {
    //     printf("%d ", delt2[i]);
    // }
    // printf("\n");
    int k = len_s - 1, i;
    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d ", delt1[i]);
    // }
    // printf("%d, %d\n", len_s, len_r);
    while (k < len_r)
    {
        // printf("k = %d\n", k);
        i = len_s - 1;
        while (r[k] == s[i])
        {
            if (i == 0)
            {
                printf("%d ", k);
                break;
            }
            i--;
            k--;
        }
        // printf("first val = %d, second val = %d", delt1[r[k]-33], delt2[i]);
        if (delt1[r[k]-33] > delt2[i])
        {
            // printf("k1 = %d, %d, %d, %d, %d\n", k + delt1[r[k]-33], k, i, r[k]-33, delt2[i]);
            k = k + delt1[r[k]-33];
        }
        else
        {
            k = k + delt2[i];
            // printf("k2 = %d\n", k);
        }

    }
}

int main(int argc, char ** argv) 
{
    char *s = argv[1];
    char *r = argv[2];
	long len_s = strlen(s);
	long len_r = strlen(r);
    BMSubst(s, r, len_s, len_r);
    return 0;
}