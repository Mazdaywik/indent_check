#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


long* prime;

long input(long n)
{
    scanf("%ld", &n);
    return n > 0 ? n : -n;
}


void init_sieve_of_Eratosthenes(long prime[], long n)
{
    for(long i = 0; i < n / 2; i++) {
        prime[i] = 1;
    }
}


void fill_sieve_of_Eratosthenes(long prime[], long n)
{
    long max_factor = pow(n, 0.5);
    for(long p = 3; p <= max_factor; p += 2) {
        if(!prime[p / 2])
            continue;

        for(int i = p * p; i < n; i += 2 * p) {
            prime[i / 2] = 0;
        }
    }
}


void print_largest_prime_factor(long prime[], long n, long init_n)
{
    for(int i = (n / 2) - 1; i >= 1; i--) {
        if(prime[i]) {

            long p = i * 2 + 1;
            if(p >= n)
                break;
            if(init_n % p == 0) {
                printf("%ld", p);
                return;
            }
        }
    }
    if(n % 2 == 0)
        printf("%d", 2);
        return;
}


void find_max_divisor(long n, long* max_div, long* max_2_div, long* max_3_div)
{
    long max_factor = pow(n, 0.5);
    int count = 0;
    for(int i = 2; i <= max_factor; i++) {
        if(n % i == 0 && count == 0) {
            *max_div = n / i;
            count++;
        }
        else if(n % i == 0 && count == 1) {
            *max_2_div = n / i;
            count++;
        }
        else if(n % i == 0 && count == 2) {
            *max_3_div = n / i;
            return;
        }
    }
}


bool is_prime(long n)
{
    long max_factor = pow(n, 0.5);
    for(int i = 2; i <= max_factor; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}


bool is_max_1_2_3_divisors_prime(long* max_divisor, long* max_second_divisor, long* max_third_divisor)
{
    if(is_prime(*max_divisor)) {
        printf("%ld", *max_divisor);
        return true;
    }

    if(is_prime(*max_second_divisor)) {
        printf("%ld", *max_second_divisor);
        return true;
    }

    if(is_prime(*max_third_divisor)) {
        printf("%ld", *max_third_divisor);
        return true;
    }
    return false;
}


int main()
{
    long n;
    n = input(n);
    long size = n;
    long n1 = n, n2 = n, n3 = n;

    long* max_divisor = &n1;
    long* max_second_divisor = &n2;
    long* max_third_divisor = &n3;

    find_max_divisor(n, max_divisor, max_second_divisor, max_third_divisor);

    if(is_max_1_2_3_divisors_prime(max_divisor, max_second_divisor, max_third_divisor))
        return 0;

    size = *max_third_divisor;

    prime = (long*)malloc(sizeof(long) * (size / 2 + 1));

    init_sieve_of_Eratosthenes(prime, size);
    fill_sieve_of_Eratosthenes(prime, size);
    print_largest_prime_factor(prime, size, n);

    free(prime);
    return 0;
}