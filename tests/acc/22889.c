#include <stdlib.h>
#include <stdio.h>
unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)){
	unsigned long nach = 0;
	unsigned long kon = nel - 1;
	while (nach <= kon){
	    if (compare((nach + kon) / 2) == 0){
	        return ((nach + kon) / 2);
	    } 
	    else if(compare((nach + kon) / 2) == 1){
	        kon = ((nach + kon) / 2) - 1;
	    }
	    else{
	        nach = ((nach + kon) / 2) + 1;
	    }
	}
	return nel;
}