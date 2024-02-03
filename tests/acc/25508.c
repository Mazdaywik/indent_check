#include <stdio.h>

void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{ 
    unsigned long max = nel - 1, min = 0;
    if (nel) {
        while (max > min) {
            for (unsigned long i = min; i < max; i++)
                if (compare(i, i + 1) == 1)
                    swap(i, i + 1);
            max--;
            for (unsigned long i = max; i > min; i--)
                if (compare(i - 1, i) == 1)
                    swap(i - 1, i);
            min++;
        }
    }
}