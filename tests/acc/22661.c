#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define SIZE 6

int mas[] = { 4, 6, 7, 5, 9, 8 };

int less(unsigned long i, unsigned long j)
{
	if (mas[i] <= mas[j]) return 1;
	else return 0;
}

unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)) {
    unsigned long left = 0;
    unsigned long right = nel - 1;

    while (left < right) {
        unsigned long mid = left + (right - left) / 2;

        if (less(mid, mid + 1)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}
