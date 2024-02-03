#include <stdio.h>
#include <string.h>


int maxarray(void* base, size_t nel, size_t width,
	int (*compare)(void* a, void* b))
{
	char* char_base = (char*)base;
	int max_id = 0;
	int *max_item = char_base;
	for (int i = 0; i < nel; ++i) {
		int* cur_item = char_base + i * width;
		if (compare(max_item, cur_item) < 0) {
			memcpy(max_item, cur_item, width);
			max_id = i;
		}
	}
	return max_id;
}