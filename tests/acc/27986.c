#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
    int count = 0, index = 0;

    while (s[index] != '\n' && s[index] != '\0')
    {
        if ((index > 0 && s[index] != ' ' && s[index] != '\t' && (s[index - 1] == ' ' || s[index - 1] == '\t')) || (index == 0 && s[index] != '\t' && s[index] != ' '))
        {
            count++;
        }   
        index++;
    }

    return count;
}

int main()
{
    char s[1002];

    fgets(s, sizeof(s), stdin);

    printf("%d", wcount(s));

    return 0;
}
