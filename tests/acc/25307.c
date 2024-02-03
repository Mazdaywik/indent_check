#include <stdio.h>

void swap(void* a, void* b, size_t width) {
	size_t store_byte;
	for (size_t i = 0; i < width; i++) {
		store_byte = *((char*)a + i);
		*((char*)a + i) = *((char*)b + i);
		*((char*)b + i) = store_byte;
	}
	return;
}
void revarray(void *base, size_t nel, size_t width)
{
	for (size_t i = 0; i < nel / 2; i++) {
		swap((void*)((size_t)base + width * i), (void *)((size_t)base + width * (nel - i - 1)), width);
	}
	return;
}

int main() {
	int array[] = {1, 2, 3, 4};
	revarray(array, 4, sizeof(int));
	for (int i = 0; i < 4; i++) {
		printf("%d", array[i]);
	}
	return 0;
}
