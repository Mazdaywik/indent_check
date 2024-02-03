#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *concat(char **s, int n)
{
    int len = 1;
    for(int i = 0; i < n; i++)
        len += strlen(s[i]);
    char *res = calloc(len, sizeof(char));
    len = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; s[i][j] != '\0'; j++)
            res[len++] = s[i][j];
    return res;
}


int main() {
    int n;
    scanf("%d", &n);
    char **s = malloc(n* sizeof(char *));
    for(int i = 0 ; i < n ; i++) {
        s[i] = calloc(1000, sizeof(char));
        scanf("%s", s[i]);
    }
    char *result = concat(s, n);
    printf("%s", result);
    free(result);
    for(int i = 0 ; i < n ; i++) {
        free(s[i]);
    }
    free(s);
}