#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(void *i, void *j, size_t width){
	for(size_t k = 0; k < width; k++){
		char s = *((char *)i + k);
		*((char *)i + k) = *((char *)j + k);
		*((char *)j + k) = s;
	}
}

int compare(const void *a, const void *b){
		int kol_a_a = 0, kol_a_b = 0;
		int lena = strlen(a), lenb = strlen(b);
		for (int i = 0; i < lena; i++){
			if(*((char *)a + i) == 'a'){
				kol_a_a = kol_a_a + 1;
			}
		}
		for (int i = 0; i < lenb; i++){
			if(*((char *)b + i) == 'a'){
				kol_a_b = kol_a_b + 1;
			}
		}
		int res = kol_a_a - kol_a_b;
		return res;
}
			
void heapify(void *base, size_t i, size_t nel, size_t width,
        int (*compare)(const void *a, const void *b)){
	while (1){
	    int l = 2 * i + 1;
	    int r = l + 1;
	    int j = i;
	    if((l < nel) && (compare((char *)base + (i * width), (char *)base + (l * width)) < 0)){
		    i = l;
	    }
	    if((r < nel) && (compare((char *)base + (i * width), (char *)base + (r * width)) < 0)){
		    i = r;
	    }
	    if(i == j){
		    break;
	    }
	    swap((char *)base + (i * width), (char *)base + (j * width), width);
	}
}
void buildheap(void *base, size_t nel, size_t width,
        int (*compare)(const void *a, const void *b)){
	int i = (nel / 2) - 1;
	while(i >= 0){
		heapify(base, i, nel, width, compare);
		i = i - 1;
	}
}
void hsort(void *base, size_t nel, size_t width,
        int (*compare)(const void *a, const void *b)){
	buildheap(base, nel, width, compare);
	int i = nel - 1;
	while (i > 0){
		swap((char *)base, (char *)base + (i * width), width);
		heapify(base, 0, i, width, compare);
		i = i - 1;
	}
}
int main(int argc , char ** argv){
	int n;
	scanf("%d", &n);
	char arr[n][1000];
	for(int i = 0; i < n; i++){
		scanf("%s", arr[i]);
	}
	hsort(arr, n, 1000, compare);
	for(int i = 0; i < n; i++){
		printf("%s\n", arr[i]);
	}
	return 0;
}