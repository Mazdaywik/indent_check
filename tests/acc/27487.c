#include <stdio.h>

unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long m) {
    unsigned long long res = 0;
    a %= m;

    while (b > 0) {
        if (b % 2 == 1) {
            res = (res + a) % m;
        }

        a = (a * 2) % m;
        b /= 2;
    }

    return res;
}

int main(void) {
    unsigned long long a, b, m;
    scanf("%llu %llu %llu", &a, &b, &m);

    unsigned long long result = mulmod(a, b, m);
    printf("%llu\n", result);

    return 0;
}