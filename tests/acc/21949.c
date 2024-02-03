#include <stdio.h>

int main() {
    unsigned long a, b, m;
    scanf("%zu", &a);
    scanf("%zu", &b);
    scanf("%zu", &m);

    unsigned long b1 = b;
    unsigned long lstb[63];
    int index = 0;
    while (b1 > 0) {
        lstb[index] = b1 % 2;
        b1 /= 2;
        index++;
    }

    unsigned long now = (lstb[index - 1] % m) * (a % m);
    for (int i = index - 2; i >= 0; i--) {
        now = ((now % m) * (2 % m)) % m;
        unsigned long ost = ((lstb[i] % m) * (a % m)) % m;
        now = (now + ost) % m;
    }

    printf("%zu\n", now);
    
    return 0;
}