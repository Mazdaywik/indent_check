#include <stdio.h>

void fibsys(unsigned long long *a, unsigned long long f1, unsigned long long f2){
    if((*a) < f2)
        return;
    fibsys(a, f2, f1 + f2);
    printf(f2 <= (*a) ? "1" : "0");
    (*a) -= f2 <= (*a) ? f2 : 0;
}


int main() {
    unsigned long long a;
    scanf("%llu", &a);
    if(a == 0){
        printf("0");
        return 0;
    }
    fibsys(&a, 1, 1);
}