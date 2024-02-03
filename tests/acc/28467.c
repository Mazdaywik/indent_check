#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 46341 

void sieveOfEratosthenes(bool isPrime[], int n) {
    for (int i = 2; i <= n; i++) {
        isPrime[i] = true;
    }

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
}

int main() {
    int x;
    scanf("%d", &x);


    unsigned int absX = abs(x);

    if (absX == 0 || absX == 1) {
        printf("%d\n", absX);
        return 0;
    }

    if (absX == 2147483648) {
        printf("2\n");
        return 0;
    }

    bool isPrime[MAX_SIZE];
    sieveOfEratosthenes(isPrime, MAX_SIZE);


    int largestPrimeDivisor = -1;
    for (int i = 2; i <= sqrt(absX) && i < MAX_SIZE; i++) {
        if (isPrime[i] && absX % i == 0) {
            largestPrimeDivisor = i;
            while (absX % i == 0) {
                absX /= i;
            }
        }
    }

    if (absX > 1) {
        largestPrimeDivisor = absX;
    }


    printf("%d\n", largestPrimeDivisor);

    return 0;
}