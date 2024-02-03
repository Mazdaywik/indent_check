#include <stdio.h>
#include <string.h>
#include <ctype.h>

int wcount(char *s)
{
    int count = 0;
    int inword = 0;
    while (*s != '\0')
    {
        if (isspace(*s) && inword)
        {
            inword = 0;
        } 
        else if (!isspace(*s) && !inword) 
        {
            inword = 1;
            count++;
        }
        s++;
    }
    return count;
}

int main()
{
    char buffer[1000];
    fgets(buffer, 1000, stdin);
    printf("%d", wcount(buffer));
    return 0;
}