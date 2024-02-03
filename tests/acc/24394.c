#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    long N;
    scanf("%ld", &N);
    long num = labs(N);
    long max = num;
    int size = (int) sqrt (num) + 2 ;
    long sieve[size];
    for(int i = 0; i < size; i++)
        sieve[i] = 0;
    for(int i = 2; i < size; ++i)
            if (sieve[i] == 0)
                for(int k = i*i; k < size; k += i)
                    sieve[k] = 1;
  
    for(int i = 2; i < size; ++i)
        if (sieve[i] == 1)
            if ((num % i) == 1)
                while((num % i) == 0)
                    num = num / i;
                    
    for(int i = 2; i < size; ++i)
        if (sieve[i] == 0)
            if ((num % i) == 0)
                while((num % i) == 0){
                    
                    num = num / i;
                    max = i;
                }
    if (max > num) printf("%ld\n", max);
    else printf("%ld\n", num);
    return 0;
}
