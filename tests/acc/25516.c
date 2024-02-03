#include <stdio.h>
#include <stdlib.h>
int less(unsigned long i, unsigned long j) {
    if(i<j) return 1;
    else return 0;
}
unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)) {
    for (unsigned long i=1; i<nel-1; i++) {
        if ((less(i-1,i)==1) && (less(i,i+1)==0)) {
            return("%lu", i);
        }
    }
}
int main() {
    unsigned long nel;
    scanf("%lu", &nel);
    peak(nel,less);
    return 0;
}