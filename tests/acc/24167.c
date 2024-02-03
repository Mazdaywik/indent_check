#include <stdio.h>
#include <string.h>
#include <malloc.h>
int maximum(int f, int s)
{
    if (f > s)
    {
        return f;
    }
    return s;
}

int *delta1(char *s)
{
    int size = 126 - 33 + 1;
    int length = strlen(s);
    int *arr = malloc(size * sizeof(int));
    int a = 0;
    while (a < size)
    {
        arr[a] = length;
        a++;
    }
    int j = 0;
    while (j < length)
    {
        arr[s[j] - 33] = length - j - 1;
        j++;
    }
    return arr;
}

int *suffix(char *s)
{
    int length = strlen(s);
    int *arr = malloc(length * sizeof(int));
    int t = length - 1;
    arr[t] = t;
    int i = length - 2;
    while (i >= 0)
    {
        while (t < length - 1 && s[t] != s[i])
        {
            t = arr[t + 1];
        }
        if (s[t] == s[i])
        {
            t--;
        }
        arr[i] = t;
        i--;
    }
    return arr;
}

int *delta2(char *s)
{
    int length = strlen(s);
    int *arr = malloc(length * sizeof(int));
    int *suff = suffix(s);
    int i = 0;
    int t = suff[0];
    while (i < length)
    {
        while (t < i)
        {
            t = suff[t + 1];
        }
        arr[i] = -i + t + length;
        i++;
    }
    i = 0;
    while (i < length - 1)
    {
        t = i;
        while (t < length - 1)
        {
            t = suff[t + 1];
            if (s[i] != s[t])
            {
                arr[t] = -(i + 1) + length;
            }
        }
        i++;
    }
    free(suff);
    return arr;
}

int main(int argc, char **argv)
{
    char *s = argv[1];
    char *t = argv[2];
    int length_s = strlen(s);
    int length_t = strlen(t);
    int *arr1 = delta1(s);
    int *arr2 = delta2(s);
    int k = length_s - 1;
    while (k < length_t)
    {
        int i = length_s - 1;
        while (t[k] == s[i])
        {
            if (i == 0)
            {
                printf("%d ", k);
                break;
            }
            i--;
            k--;
        }
        k += maximum(arr1[t[k] - 33], arr2[i]);
    }
    free(arr1);
    free(arr2);
    return 0;
}