#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int wcount(char *s)
{
    long long i = 0;
    char ch = s[i];
    int c = 0;
    if (s[0] == '\0') return 0;
    // printf("%c\n", s[i]);
    while (ch == ' ')
    {
        i++;
        ch = s[i];
    }
    while (s[i] != '\0')
    {
        // printf("%c", s[i]);
        ch = s[i];
        if (ch == ' ')
        {
            c++;
            while (ch == ' ')
            {
                i++;
                ch = s[i];
            }
            i--;
        }
        i++;
    }
    if (s[i-1] != ' ')
    {
        c++;
    }
    return c;
}

int main() {
    char s[512];
    gets(s);
    printf("%d", wcount(s));
    return 0;
}



