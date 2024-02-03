#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    unsigned long long right = nel - 1, left = 0, middle = (right + left) / 2;

    while (left <= right)
    {
        if (compare(middle) == 0) { return middle; }
        if (compare(middle) == 1) {  right = middle - 1; }
        else{ left = middle + 1; }
        middle = (right + left) / 2;
    }

    return nel;
}