#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revarray(void *base, size_t nel, size_t width)
{
	int* mid = malloc(width);
	char* char_base = (char*)base;
;	for (int i = 0; i < nel / 2; ++i) {
		char *left = char_base + i * width, *right = char_base + (nel - i - 1) * width;
		memcpy(mid, left, width);
		memcpy(left, right, width);
		memcpy(right, mid, width);
	}
	free(mid);
}