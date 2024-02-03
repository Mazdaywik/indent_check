#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 46341

void buildSieve(bool sieve[], int size) 
{
    for (int i = 2; i * i <= size; ++i) 
    {
        if (sieve[i]) 
        {
            for (int j = i * i; j <= size; j += i)
                sieve[j] = false;
        }
    }
}

int findPrimeDiv(int x, bool sieve[]) 
{
    int PrimeDiv = 1;
    for (int i = 2; i <= x && i < MAX_SIZE; ++i) 
    {
        if (sieve[i] && x % i == 0) 
        {
            PrimeDiv = i;
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1 && x > PrimeDiv)
        PrimeDiv = x;
    return PrimeDiv;
}

int main() 
{
    int x;
    scanf("%d", &x);
    if (x == -2147483648) 
    {
        printf("2\n");
        return 0;
    }
    bool sieve[MAX_SIZE + 1];
    for (int i = 0; i <= MAX_SIZE; ++i)
        sieve[i] = true;
    buildSieve(sieve, MAX_SIZE);
    int PrimeDiv = findPrimeDiv(abs(x), sieve);
    printf("%d\n", PrimeDiv);
    return 0;
}