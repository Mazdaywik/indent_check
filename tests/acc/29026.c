#include <stdio.h>

void fibsys(unsigned long long x) {
    if (x == 0) {
        printf("0\n");
        return;
    }

    unsigned long long fib[90]; 
    fib[0] = 1;
    fib[1] = 2;

    int i = 2;
    while (fib[i - 1] <= x) {
        fib[i] = fib[i - 1] + fib[i - 2];
        i++;
    }

    int started = 0;

    for (int j = i - 1; j >= 0; --j) {
        if (fib[j] <= x) {
            printf("1");
            x -= fib[j];
            started = 1;
        } else if (started) {
            printf("0"); 
        }
    }

    printf("\n");
}

int main() {
    unsigned long long x;
    scanf("%llu", &x);

    fibsys(x);

    return 0;
}
