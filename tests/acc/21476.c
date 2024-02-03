#include <stdio.h>

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    unsigned long left = 0;
    unsigned long right = nel - 1;
    while (left <= right) {
        unsigned middle = (left + right) / 2;
        if (compare(middle) == -1) left = middle + 1;
        else if (compare(middle) == 1) right = middle - 1;
        else return middle;
    }
    return nel;
}