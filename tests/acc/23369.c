#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a>b? a : b

struct list{
    long long val;
    struct list *next;
};

int isPrime(long long num, struct list *primes){
    if (num == 1)
        return 0;
    while (primes != NULL){
        if(num%primes->val == 0)
            return 0;
        primes = primes->next;
    }
    return 1;
}

long long notD(long long num, long long d){
    while (num%d == 0)
        num/=d;
    return num;
}

struct list *prime(long long num){
    struct list *primes = malloc(sizeof(struct list));
    struct list *end = primes;
    primes->val = 2;
    primes->next = NULL;
    long long d = 3;
    while (d*d <= num){
        if (isPrime(d, primes)){
            end->next = malloc(sizeof(struct list));
            end = end->next;
            end->val = d;
            end->next = NULL;
        }
        d++;
    }
    return primes;
}


int main() {
    long long num;
    scanf("%lld", &num);
    if (num < 0)
        num = -num;
    struct list *primes = prime(num);
    struct list *now = primes;
    long long max = 0, save = num;
    while (now != NULL){
        if (num % now->val == 0){
            max = max = max(now->val, max);
            num = notD(num, now->val);
            if(isPrime(num, primes)){
                max = max(num, max);
            }
        }
        now = now->next;
    }
    if (max == 0)
        max = save;
    printf("%lld", max);
    while (primes !=NULL){
        struct list *next = primes->next;
        free(primes);
        primes = next;
    }
    return 0;
}