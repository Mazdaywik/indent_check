#include <stdio.h>
int main(void) {
    unsigned long long a;
    scanf("%llu", &a);
    unsigned long long b;
    scanf("%llu", &b);
    unsigned long long m;
    scanf("%llu", &m);
    int power = 0;
    int power2;
    unsigned long long h[100];
    unsigned long long result = 0;
    unsigned long long f;
    while (a > 0) {
        if (a % 2 == 0) {
            h[power] = 0;
            a = a / 2;
        } else {
            h[power] = 1;
            a = (a - 1) / 2;
        }
        power = power + 1;
    }
    power2 = power;

    while (power > 0) {
        if (power == power2) {
            result = (b * 2 * h[power - 1]) % m;
            power = power - 1;
        } else {
            if (power == power2 - 1) {
                f = (b * h[power - 1]) % m;
                result = (result + f) % m;
                power = power - 1;
            } else {
                f = (b * h[power - 1]) % m;
                result = (result * 2 + f) % m;
                power = power - 1;
            }
        }
    }

    printf("%llu", result);

    return (0);
}