#include <stdio.h>

void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j))
{

    if (nel > 0)
    {
        for (size_t i = 0; i < nel - 1; i++)
        {

            if (i % 2 == 0)
            {
                // -->
                for (size_t j = i / 2; j < nel - 1 - i / 2; j++)
                {
                    if (compare(j, j + 1) > 0)
                    {
                        swap(j, j + 1);
                    }
                }
            }
            else
            {
                // <--
                for (size_t j = nel - 1 - i / 2; j > i / 2; j--)
                {
                    if (compare(j, j - 1) < 0)
                    {
                        swap(j, j - 1);
                    }
                }
            }
        }
    }
}