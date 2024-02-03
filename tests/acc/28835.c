#include <stdio.h>

unsigned long peak(unsigned long nel,
        int (*less)(unsigned long i, unsigned long j))
{
	unsigned int previous_peak = 1;
	
	if (nel <= 1)
		return 0;
	
	for (unsigned long index = 1; index < nel; index++)
	{
		if (previous_peak && !less(index-1, index))
			return index - 1;
		
		previous_peak = !less(index, index-1);
	}
	
	if (previous_peak)
		return nel - 1;
}