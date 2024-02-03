#include <stdio.h>

int main() {
    unsigned long long x;
    scanf("%llu", &x);
    if (x == 0UL) {
        printf("%d", 0);
        return 0;
    }
    unsigned long long a = 1, b = 1;
    while (b <= x) {
        unsigned long long c = a + b;
        a = b;
        b = c;
    }
    unsigned long long c = b - a;
    b = a;
    a = c;
    while (a != 0) {
        if (x >= b) {
            printf("%d", 1);
            x -= b;
        } else {
            printf("%d", 0);
        }
        c = b - a;
        b = a;
        a = c;
    }
    return 0;
}