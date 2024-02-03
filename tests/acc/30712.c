#include <stdio.h>
void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    int lshift = 0;
    int rshift = nel - 1;
    for (unsigned long i = 0; i < nel; i++) {
        if (i % 2 == 0) {
	    for (unsigned long j = lshift; j < rshift; j++) {
	        if (compare(j, j + 1) == 1) {
		    swap(j, j + 1);
		}
	    }
	    rshift--;
	}
		
	else {
	    for (unsigned long j = rshift; j > lshift ; j--) {
		if (compare(j, j-1) == -1) {
		    swap(j, j -1);
		}
	    }
	    lshift++;
	}
    }
}