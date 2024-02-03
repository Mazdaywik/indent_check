#include <stdio.h>



void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
        unsigned long start = 0, end = nel - 1, i;
        if(nel != 0){
                while(start < end){
                for(i = start; i < end; i++)
                        if(compare(i, i + 1) == 1)
                                swap(i, i + 1);
                end--;
                for(i = end;i > start;i--)
                        if(compare(i, i - 1) == -1)
                                swap(i, i - 1);
                start++;
        }
        }
}
