#include <stdio.h>

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
	unsigned long lower = 0;
	unsigned long upper = nel-1;
	
	while (lower <= upper)
	{
		unsigned long middle = (lower == upper) ? lower : lower / 2 + upper / 2;
		
		int comparison = compare(middle);
		
		if (comparison == 0)
			return middle;
		
		if (comparison == -1)
		{
			lower = middle + 1;
		}
		else
		{
			upper = middle - 1;
		}
	}
	
	return nel;	
}