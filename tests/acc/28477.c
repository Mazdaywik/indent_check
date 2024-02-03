#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

uint64_t largestPrimeDivisor(uint64_t n) {
    if (n == 0) {
        return -1;
    }

    if (n < 2) {
        return 1;
    }

    uint64_t maxDivisor = 1;
    uint64_t sqrtN = (uint64_t)sqrt(n);

    bool* isPrime = (bool*)malloc((sqrtN + 1) * sizeof(bool));
    for (uint64_t i = 2; i <= sqrtN; i++) {
        isPrime[i] = true;
    }

    for (uint64_t i = 2; i <= sqrtN; i++) {
        if (isPrime[i]) {
            for (uint64_t j = i * i; j <= sqrtN; j += i) {
                isPrime[j] = false;
            }

            while (n % i == 0) {
                maxDivisor = i;
                n /= i;
            }
        }
    }

    free(isPrime);

    if (n > 1) {
        maxDivisor = n;
    }

    return maxDivisor;
}

int main() {
    uint64_t num;

    scanf("%llu", &num);

    uint64_t result = largestPrimeDivisor(llabs(num));

    printf("%llu\n", result);

    return 0;
}
