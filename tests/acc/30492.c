#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* aa, const void* bb) {
	const char* a = *(const char**)aa;
	const char* b = *(const char**)bb;
	int count1 = 0, count2 = 0;
	int i = 0;
	while (a[i] != '\0') {
		if (a[i] == 'a') count1++;
		i++;
	}
	i = 0;
	while (b[i] != '\0') {
		if (b[i] == 'a') count2++;
		i++;
	}
	return count1 - count2;
}

void swap(void* aa, void* bb, size_t width) {
	char* a = (char*)aa;
	char* b = (char*)bb;
	for (size_t i = 0; i < width; i++) {
		char t = a[i];
		a[i] = b[i];
		b[i] = t;
	}
}

void heapify(void* base, size_t nel, size_t i, int (*compare)(const void* a, const void* b), size_t width) {
	size_t m = 1;
	while (m == 1) {
		size_t l = 2 * i + 1;
		size_t r = l + 1;
		size_t j = i;
		if ((l < nel) && (compare((char*)base + width * i, (char*)base + width * l) < 0)) {
			i = l;
		}
		if ((r < nel) && (compare((char*)base + width * i, (char*)base + width * r) < 0)) {
			i = r;
		}
		if (i == j) break;
		swap((char*)base + width * i, (char*)base + width * j, width);
	}
}

void buildheap(void* base, size_t nel, int (*compare)(const void* a, const void* b), size_t width) {
	for (size_t i = nel / 2; i > 0; i--) {
		heapify(base, nel, i - 1, compare, width);
	}
}

void hsort(void* base, size_t nel, size_t width, int (*compare)(const void* a, const void* b)) {
	buildheap(base, nel, compare, width);
	for (size_t i = nel; i > 0; i--) {
		swap((char*)base, (char*)base + (i - 1) * width, width);
		heapify(base, i - 1, 0, compare, width);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	char** base = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++) {
		base[i] = (char*)malloc(1001 * sizeof(char));
		scanf("%s", base[i]);
	}
	hsort(base, n, sizeof(base[0]), compare);
	for (int i = 0; i < n; i++) {
		printf("%s\n", base[i]);
		free(base[i]);
	}
	free(base);
	return 0;
}