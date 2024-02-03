#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 46341

int findLargestPrimeDivisor(long long x) {
    bool *sieve = (bool *)malloc(MAX_SIZE * sizeof(bool));

    for (int i = 0; i < MAX_SIZE; ++i) {
        sieve[i] = true;
    }

    for (int p = 2; p * p < MAX_SIZE; ++p) {
        if (sieve[p]) {
            for (int i = p * p; i < MAX_SIZE; i += p) {
                sieve[i] = false;
            }
        }
    }

    int largestPrimeDivisor = 1;

    for (int i = 2; i <= sqrt(llabs(x)) && i < MAX_SIZE; ++i) {
        if (sieve[i] && x % i == 0) {
            largestPrimeDivisor = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }

    if (x > 1) {
        largestPrimeDivisor = x;
    }

    free(sieve);

    return largestPrimeDivisor;
}

int main() {
    long long x;
    scanf("%lld", &x);

    int result = findLargestPrimeDivisor(llabs(x));

    printf("%d\n", result);

    return 0;
}
