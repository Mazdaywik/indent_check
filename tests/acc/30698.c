#include <stdio.h>
void left (int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j),
	unsigned long *t, unsigned long *bound)
{
	unsigned long leftind=0;
	while (leftind<*bound) {
		if (compare (leftind, leftind+1)>0) {
			swap(leftind, leftind+1);
			*t=leftind;
		}
		leftind++;
	}
	*bound=*t;
}
void right (int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j),
	unsigned long *t, unsigned long *bound)
{
	unsigned long rightind=*bound;
	while (rightind>1) {
		if (compare (rightind-1, rightind)>0) {
			swap(rightind-1, rightind);
			*t=rightind;
		}
		rightind--;
	}
}
void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
        if (nel>0) {
	    unsigned long t=nel-1, bound=t;
	    while (t>0) {
		    t=0;
		    left (compare, swap, &t, &bound);
		    if (t==0) break;
		    right (compare, swap, &t, &bound);
		    if (t==0) break;
	    }
        }
}