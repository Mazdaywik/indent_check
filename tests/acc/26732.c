#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b))
{
	void *max = malloc(width);
	memcpy(max, base, width);
	int ind = 0;
	
	for (int i = 1; i < nel; i++)
	{
		int comparation = 0;
		comparation = compare((char*)base + i * width, max);
		
		if (comparation > 0)
		{
			memcpy(max, (char*)base + i * width, width);
			ind = i;
		}
	}
	
	free(max);
	return ind;
}