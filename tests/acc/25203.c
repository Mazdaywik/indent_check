#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}
int prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return n;
}

void SieveOfEratosthenes(int n) {
    unsigned int N = abs(n);
    int sqrtN = (int) (sqrt(N));
    bool isPrime[sqrtN+1];
    for (int i = 0; i <= sqrtN; i++) {
        isPrime[i] = true;
    }
    for (int i = 2; i * i <= sqrtN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= sqrtN; j += i)
                isPrime[j] = false;
        }
    }
    int max_div = 0;
    for (int i = 1; i <= sqrtN; i++) {
        if ((N%i == 0))
            max_div = max(max_div, prime(N / i));
        if ((N%i == 0) && (isPrime[i])) {
            max_div = max(max_div, max(i, prime(N / i)));
        }
    }
    printf("%d ", max_div);
}

int main() {
    int n;
    scanf("%d", &n);
    SieveOfEratosthenes(n);
    return 0;
}