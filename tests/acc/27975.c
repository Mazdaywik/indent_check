#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char **s, int n)
{
    int lenNewStr = 0;

    for (int i = 0; i < n; ++i)
    {
        lenNewStr += strlen(s[i]);
    }

    char *newStr = (char*)malloc(sizeof(char) * (lenNewStr + 1));

    int index  = 0;

    for (int i = 0; i < n; ++i)
    {
        int indexS = 0;

        while (s[i][indexS] != '\0')
        {
            newStr[index++] = s[i][indexS++];
        }
    }
    
    newStr[index] = '\0';

    return newStr;
}

int main()
{
    int n;
    
    scanf("%d", &n);

    if (n == 0){
        return 0;
    }
    
    char **strings = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        strings[i] = (char *)malloc(1001 * sizeof(char));
        scanf("%1000s", strings[i]);
    }

    char *result = concat(strings, n);

    printf("%s", result);

    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);
    free(result);

    return 0;
}