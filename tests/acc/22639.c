#include <stdio.h>

unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long m) {
    unsigned long long res = 0;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res + a) % m;
        }
        b = b / 2;
        a = (a * 2) % m;
    }
    return res;
}

int main() {
    unsigned long long a, b, m;
    scanf("%llu %llu %llu", &a, &b, &m);
    unsigned long long res = mulmod(a, b, m);
    printf("%llu\n", res);

    return 0;
}