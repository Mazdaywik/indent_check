#include <stdio.h>
#include <string.h>
#define MIN(a, b) (a > b)?(b):(a)

int strdiff(char *a, char *b)
{
    int lenA = strlen(a), lenB = strlen(b), count = 0;

    for (int i = 0, j = 0; i <= lenA && j <= lenB; ++i, ++j)
    {
        for(int index = 0; index <= 7; ++index)
        {
            if (((a[i] >> index) & 1) == ((b[j] >> index) & 1))
            {
                count++;
            }
            else
            {
                return count;
            }
        }
    }

    if (lenA == lenB)
    {
        return -1;
    }
    else
    {
        return 8 * MIN(lenA, lenB);
    }
}