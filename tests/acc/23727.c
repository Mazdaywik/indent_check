    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <math.h>

    int* buildSieve(int limit) {
        bool* isPrime = (bool*)malloc((limit + 1) * sizeof(bool));
        for (int i = 2; i <= limit; i++) {
            isPrime[i] = true;
        }
        for (int p = 2; p * p <= limit; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= limit; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        int* primes = (int*)malloc((limit / 2) * sizeof(int));
        int primeCount = 0;
        for (int p = 2; p <= limit; p++) {
            if (isPrime[p]) {
                primes[primeCount++] = p;
            }
        }
        primes[primeCount] = 0;  
        free(isPrime);
        return primes;
    }

    int largestPrimeDivisor(int x, int* primes) {
        int largestDivisor = -1;
        int limit = abs(x);
        for (int i = 0; primes[i] != 0 && primes[i] <= limit; i++) {
            if (x % primes[i] == 0) {
                largestDivisor = primes[i];
                while (x % primes[i] == 0) {
                    x /= primes[i];
                }
            }
        }
        if (abs(x) > largestDivisor) {
            largestDivisor = x;
        }
        return abs(largestDivisor);
    }

    int main() {
        int x;
        
        scanf("%d", &x);
        if (x == -2147483648){
            printf("2");
        }
        else{
            int limit = (int)sqrt(abs(x));  
            int* primes = buildSieve(limit);
            int result = largestPrimeDivisor(x, primes);

            printf("%d", result);

            free(primes); 
        }
        
        return 0;
    }
