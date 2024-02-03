#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revarray (void *base, size_t nel, size_t width)
{
	void* holder = malloc(width);
	
	for (int i = 0; i < nel / 2; i++)
	{
		memcpy(holder, (char*)base + i * width, width);
		memcpy((char*)base + i * width, (char*)base + (nel - i - 1) * width, width);
		memcpy((char*)base + (nel - i - 1) * width, holder, width);
	}
	
	free(holder);
}