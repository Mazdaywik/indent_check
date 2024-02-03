#include <stdio.h>

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
	unsigned long start = 0;
	unsigned long end = nel - 1;
	unsigned long mid, f;
	
    while (start <= end) {
	mid = (start + end) / 2;
        f = compare(mid);
	if (f == 0) {
		return mid;
	}
        if (f == -1) {
		start = mid + 1;
	}
	if (f == 1) {
		end = mid - 1;
	}
    }
    return nel;
}