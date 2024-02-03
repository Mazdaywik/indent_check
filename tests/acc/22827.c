#include <stdio.h>
void dec_to_bin(unsigned long b, int s[64]) {
    for (int i = 63; i >= 0; i--) {
        s[i] = b % 2;
        b /= 2;
    }
}
int main(int argc, char **argv)
{
    unsigned long a, b, mod = 0, m;
    int i;
    scanf("%lu %lu %lu", &a, &b, &m);
    int  s[64] = {0};
    dec_to_bin(b, s);
    mod = (((a % m) * s[0] * 2) % m + ((a % m) * s[1])) % m;
    for (i = 2; i < 64; i++) {
        mod = (((mod * 2) % m) + (a % m) * s[i]) % m;
    }
    printf("%lu", mod);
}