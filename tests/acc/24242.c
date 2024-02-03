#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat(char **s, int n)
{
    long size = 1;

    for (size_t i = 0; i < n; i++)
    {
        size += strlen(s[i]);
    }

    char *str = (char *)malloc(size);
    strcpy(str, "");

    size = 0;
    for (size_t i = 0; i < n; i++)
    {
        memcpy(str + size, s[i], strlen(s[i]) + 1);
        size += strlen(s[i]);
    }

    return str;
}


void main()
{
    int n = 0;
    scanf("%d", &n);
    char **s = (char **)malloc(n * sizeof(char *));
    for (size_t i = 0; i < n; i++)
    {   
        s[i] = (char *)malloc(1000);
        scanf("%s", s[i]);
    }

    char *new = concat(s, n);
    printf("%s", new);
    
    free(new);
    new = NULL; 

    for (size_t i = 0; i < n; i++)
    {
        free(s[i]);
        s[i] = NULL;
    }

    free(s);
    s = NULL;    

    // // Ввод через fgets 
    // char q[1000];
    // fgets(q, 1000, stdin);
    // int n = atoi(q);

    // char **s = (char **)malloc(n * sizeof(char *));

    // for (size_t i = 0; i < n; i++)
    // {   
    //     s[i] = (char *)malloc(1000);
    //     fgets(s[i], 1000, stdin);
    //     strcpy(s[i], strtok(s[i], "\n"));
    //     // s[strcspn(s[i], "\n") + 1] = 0;
    // }
}