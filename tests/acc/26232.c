#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPSArray(char* S, int M, int* lps) 
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) 
    {
        if (S[i] == S[len]) 
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0) 
                len = lps[len - 1];
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpAll(char* S, char* T) 
{
    int M = strlen(S);
    int N = strlen(T);
    int* lps = (int*)malloc(M * sizeof(int));
    computeLPSArray(S, M, lps);
    int i = 0;
    int j = 0;
    while (i < N) 
    {
        if (S[j] == T[i]) 
        {
            j++;
            i++;
        }
        if (j == M) 
        {
            printf("%d ", i - j);
            j = lps[j - 1];
        }
        else if (i < N && S[j] != T[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    free(lps);
}

int main(int argc, char* argv[]) 
{
    if (argc != 3) 
    {
        printf("Usage: ./kmpall <substring> <string>\n");
        return 1;
    }
    char* S = argv[1];
    char* T = argv[2];
    kmpAll(S, T);
    return 0;
}