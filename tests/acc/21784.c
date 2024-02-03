#include <stdio.h>


int main() {
    unsigned long long int a, b, m;
    scanf("%lld %lld %lld", &a, &b, &m);
    int bbin[63] = {0};
    int i = 0;
    while (b) {
        bbin[i] = b % 2;
        b /= 2;
        i++;
    }

    unsigned long long int res = a * bbin[i - 1];
    for (int k = 0; k < i - 1; k++) {
        res = (res % m) * 2;
        res = (res % m) + (a % m) * (bbin[i - k - 2] % m);
    }
    printf("%lld", res % m);

    return 0;
}