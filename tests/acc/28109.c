#include <stdio.h>
#include <string.h>

#define MAXLINE 1000001

void DistributionSort(char string[], int length)
{
    int countAlp[26] = {0};
    int i;

    for (i = 0; i < length; ++i)
    {
        countAlp[(int)string[i] - (int)'a']++;
    }

    char output[MAXLINE];
    int pos = 0;

    for (i = 0; i < 26; ++i)
    {
        memset(output + pos, 'a' + i, countAlp[i]);
        pos += countAlp[i];
    }

    output[pos] = '\0';

    printf("%s", output);
}

int main()
{
    char str[MAXLINE];

    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1; 
    }

    int length = (int)strlen(str);
    if (str[length - 1] == '\n')
    {
        str[length - 1] = '\0';
        length--; 
    }

    DistributionSort(str, length);

    return 0;
}
