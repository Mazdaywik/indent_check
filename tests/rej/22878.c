#include <stdlib.h>
#include <stdio.h>
int maxarray(void *base, size_t nel, size_t width, 
		int (*compare)(void *a, void *b)){
	if (nel == 0){
		return 0;
	}
	int indmaxx = 0;
	for (size_t i = 0; i < nel; i++){
		if (compare ((((char *) base) + (i * width)),
		(((char *) base) + (indmaxx * width))) > 0){
			indmaxx = i;
	}}
	return indmaxx;
		}