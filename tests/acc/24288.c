#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strdiff(char *a, char *b)
{

    int minlen = 0;
    if (strlen(a) >= strlen(b))
    {
        minlen = strlen(b) + 1;
    }
    else
    {
        minlen = strlen(a) + 1;
    }

    int same_count = 0;
    for (size_t i = 0; i < minlen; i++)
    {
        int j = a[i] ^ b[i];

        if (j == 0)
        {
            same_count += 8;
        }
        else
        {
            int k = 0;
            j = abs(j);
            while (j != 0)
            {
                if (j % 2 == 1)
                {
                    same_count += k;
                    break;
                }
                k++;
                j /= 2;
            }
            break;
        }
    }

    if (strlen(a) == strlen(b) && minlen * 8 == same_count)
    {
        return -1;
    }
    else
    {
        return same_count;
    }
}