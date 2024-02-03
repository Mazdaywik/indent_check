#include <stdio.h>

#define MIN(a, b) ((a > b) ? (b) : (a)) 
#define MAX(a, b) ((a > b) ? (a) : (b))

long long mulmod(unsigned long a, unsigned long long b, unsigned long long m){
    if (b > 0ULL){
        return ((mulmod(a, b / 2, m)) * 2 % m + a * (b % 2)) % m;
    }
    else{
        return 0;
    }
}

int main(){
    unsigned long long a, b, m;
    scanf("%llu %llu %llu", &a, &b, &m);
    printf("%llu", mulmod(MIN(a, b) % m, MAX(a, b), m));
}
