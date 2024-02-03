#include <stdio.h>
#include <stdlib.h>


void shellsort(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j)) 
{
    if (nel > 1) {
        // последовательность Фибоначчи
        unsigned long first = 1, second = 1;
        while (second < nel) { 
            unsigned long tmp = second;
            second = first + second;
            first = tmp;
        }

        while (first > 0) {
            unsigned long step = first;
            for (unsigned long i = step; i < nel; ++i) {
                for (long j = i; j >= step && compare(j - step, j) > 0; j -= step) {
                    swap(j - step, j);
                }
            }

            unsigned long tmp = second - first;
            second = first;
            first = tmp;
        }
    }
}