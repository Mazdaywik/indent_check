#include <stdio.h>
#define long unsigned long long

long mulmod(long a, long b, long m, long res, long s2){
    return s2==1 ? (res*2%m + (a & s2 ? b % m : 0)) % m :\
    mulmod(a, b, m, (res*2%m + (a & s2 ? b % m : 0))%m, s2>>1) % m;
}
int main() {
    long a, b, m;
    scanf("%lld%lld%lld", &a, &b, &m);
    printf("%lld", mulmod(a, b, m, 0, (long)1<<62));
    return 0;
}