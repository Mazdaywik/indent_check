#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 46341

void eratsieve(bool is_prime[], int primes[], int *count) {
    for (int i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            primes[*count] = i;
            *count = *count + 1;
            for (int j = i * i; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
int main() {
    int x;
    scanf("%d", &x);
    bool is_prime[MAX];
    for (int i = 2; i < MAX; i++) {
        is_prime[i] = true;
    }
    int primes[MAX];
    int count = 0;
    eratsieve(is_prime, primes, &count);
    int max_prime = 1;
    int abs_x = abs(x);
    for (int i = 0; i < count; i++) {
        if (abs_x % primes[i] == 0) {
            max_prime = primes[i];
            while (abs_x % primes[i] == 0) {
                abs_x /= primes[i];
            }
        }
    }
    if (abs_x > 1) {
        max_prime = abs_x;
    }
    printf("%d\n", max_prime);

    return 0;
}