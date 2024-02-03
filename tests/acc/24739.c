#include <stdio.h>


unsigned long peak(unsigned long nel,
        int (*less)(unsigned long i, unsigned long j))
{

        if(nel == 1) return 0;
        if((nel == 2) && (less(0, 1) == 0)) return 2;
        if((nel == 2) && (less(0, 1) != 0)) return 1;


        unsigned long i;
        char r = 0;

        for(i = 0; i < nel - 1; i++){

        if(less(i, i + 1) == -1) {if(r == 1) return i; r = 0;}
        else if (less(i, i + 1) == 1) r = 1;
        else{if(r == 1) return i; r = 1;}
        }
        return 0;
}