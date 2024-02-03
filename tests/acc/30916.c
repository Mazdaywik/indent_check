#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(void *a, void *b, size_t width) {
	char *mass_a =(char*)a;
	char *mass_b =(char*)b;
	char temp;
	for (int i = 0; i < width; i++){
		temp = mass_a[i];
		mass_a[i] = mass_b[i];
		mass_b[i] = temp;
	}
}
int compare(const void *a, const void *b) {
	char *a_value=(char *)a;
	char *b_value=(char *)b;
	int count_a=0, count_b=0;
	for (int i=0; i<strlen(a_value); i++) if (a_value[i]=='a') count_a++;
	for (int i=0; i<strlen(b_value); i++) if (b_value[i]=='a') count_b++;
	return count_a-count_b;
}
void heapify(int (*compare)(const void *a, const void *b), size_t *base, size_t i, size_t nel, size_t width)
{
	while (1) {
		int left=2*i+1;
		int right=2*i+2;
		int largest=i;
		if (left<nel && compare((char *)base+i*width, (char *)base+left*width)<0) i=left;
		if (right<nel && compare((char *)base+i*width, (char *)base+right*width)<0) i=right;
		if (i==largest) break;
		swap((char*)base+largest*width, (char *)base +i*width, width);
	}
}
void buildheap(int (*compare)(const void *a, const void *b), void *base, size_t nel, size_t width) {
	for (int i=(int)nel/2-1; i>=0; i--) heapify(compare, base, i, nel, width);
}
void hsort(void *base, size_t nel, size_t width,
        int (*compare)(const void *a, const void *b))
{
	buildheap(compare, base, nel, width);
	size_t i=nel-1;
	while (i>0) {
		swap(base, (char *)base +i*width, width);
		heapify(compare, base, 0, i, width);
		i--;
	}
}
int main() {
	int nel;
	scanf("%d", &nel);
	char s[nel][1000];
	for (int i=0; i<nel; i++) scanf("%s", s[i]);
	hsort(s, nel, 1000, compare);
	for (int i=0; i<nel; i++) printf("%s\n", s[i]);
	return 0;
}