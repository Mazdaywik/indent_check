#include <stdio.h>
void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j)){
            if(nel <= 1){
                return;
            }
            unsigned long nach = 0;
            unsigned long kon = nel - 1;
            while (nach < kon){
				for(unsigned long i = nach; i < kon; i++){
					if (compare(i, i + 1) == 1){
						swap(i, i + 1);
					}
				}
				kon = kon - 1;
				for(unsigned long j = kon; j > nach; j--){
					if(compare(j, j - 1) == -1){
						swap(j, j - 1);
					}
				}
				nach = nach + 1;
			}
}