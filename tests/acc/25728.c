#include<stdio.h>
long long MulMod(unsigned long long a, unsigned long long b, unsigned long long m) {
    unsigned long long res = 0;
    a %= m;
    while (b) {
        if (b & 1)
            res = (res + a % m) % m;
        a = (2 * a) % m;
        b = b / 2;
    }
    return res;
}
int main() {
    long long a, b, m;
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &m);
    printf("%lld", MulMod(a, b, m) % m);
    return 0;
}
