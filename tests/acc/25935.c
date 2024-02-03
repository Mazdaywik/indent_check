#include <stdio.h>

unsigned long long int mulmod(unsigned long long int a, unsigned long long int b, unsigned long long int m) {
    if (a >= m) a %= m;
    if (b >= m) b %= m;

    unsigned long long int res = 0;
    while (b > 0) {
        if (b & 1)  
            res = (res + a) % m;
        a = (a * 2) % m;
        b >>= 1;  
    }
    return res;
}


int main() {
    unsigned long long a, b, m;
    scanf("%llu%llu%llu", &a, &b, &m);
    printf("%llu", mulmod(a, b, m));
    return 0;
}