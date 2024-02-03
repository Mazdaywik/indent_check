#include <stdio.h>

unsigned long long fibonacci[100];

void precompute_fibonacci() {
    fibonacci[0] = 1;
    fibonacci[1] = 2;
    for (int i = 2; i < 100; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

void fib_sys_representation(unsigned long long x) {
    if (x == 0) {
        printf("0\n");
        return;
    }

    int highest_fib_index = -1;

    for (int i = 0; i < 100; i++) {
        if (fibonacci[i] > x) {
            highest_fib_index = i - 1;
            break;
        }
    }

    for (int i = highest_fib_index; i >= 0; i--) {
        if (fibonacci[i] <= x) {
            printf("1");
            x -= fibonacci[i];
        }
        else {
            printf("0");
        }
    }

    printf("\n");
}

int main() {
    unsigned long long x;
    precompute_fibonacci();
    scanf("%llu", &x);
    fib_sys_representation(x);

    return 0;
}
