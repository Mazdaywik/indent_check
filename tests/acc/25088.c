#include<stdio.h>

int prevfib(int a){
        int fib1 = 0, fib2 = 1;
        while(fib2 < a){
                fib2 = fib2 + fib1;
                fib1 = fib2 - fib1;
        }
        return fib1;
}

void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
        {
        int i, loc;
        int d = prevfib(nel);
        while(d > 0){
                i = 0;
                while(i < nel - d){
                        loc = i;
                        while((loc >= 0) && (compare(loc, loc + d) > 0)){
                                swap(loc + d, loc);
                                loc-= d;
                         }
                        i++;
                }
                d = prevfib(d);
        }
}