#include <stdio.h>
#include <stdlib.h>
void revarray(void *base, size_t nel, size_t width){
	for(size_t i = 0; i < (nel / 2); ++i){
		for (size_t j = 0; j < width; ++j){
		    size_t p;
			p = 
			*(((char *) base) + (i * width) + j);
			*(((char *) base) + (i * width) + j) = *(((char *) base) + ((nel - i - 1) * width) + j);
			*(((char *) base) + ((nel - i - 1) * width) + j) = p;
		}
	}
}