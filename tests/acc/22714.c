#include <stdio.h>

int wcount(char *s)
{
    int i, res;
    i = 0;
    res = 0;
    while (s[i] != '\0'){
        res = s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0') ? res + 1 : res;
        i ++;
    }
    return res;
}

int main()
{
    char s[10000];
    gets(s);
    int a = wcount(s);
    printf("%d", a);

    return 0;
}