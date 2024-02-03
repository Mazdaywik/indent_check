#include <stdio.h>

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
        unsigned long left = 0, right = nel, index;

        while (left < right){
            index = (right + left) / 2;
            if (compare(index) == 0){
                return index;
            }
            else if (compare(index) == -1){
                left = index + 1;
            }
            else{
                right = index ;
            }
        } 

        return nel;
}