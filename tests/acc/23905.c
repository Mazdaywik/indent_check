#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){
    long long x;
    scanf("%lld", &x);

    long long fib_basis [94];
    fib_basis [0] = 1;
    fib_basis [1] = 2;
    long long len_fib = 2;
    while (fib_basis [len_fib - 1] < x)
    {
        fib_basis [len_fib] = fib_basis [len_fib - 2] + fib_basis [len_fib - 1];
        len_fib = ++len_fib;
    }
    if (x != fib_basis[len_fib - 1])
    {
        len_fib -=1;
    }

    long long *fib_num = malloc(len_fib * sizeof(*fib_num));
    memset(fib_num, 0, len_fib * sizeof(* fib_num));

    long long * p_fib_basis = & fib_basis [len_fib - 1];
    long long * p_fib = & fib_num [len_fib - 1];
    long long * p_fib_num = & fib_num [0];

    do
    {
        if (x >= *p_fib_basis)
        {
            x -= *p_fib_basis;
            * p_fib = 1;
        } else {
            * p_fib = 0;
        }
        -- p_fib;
        -- p_fib_basis;
    } while (p_fib >= p_fib_num);
    
    for (long long a = (len_fib - 1); a >= 0 ; a--)
    {
        printf ("%lld", fib_num[a]);
    }
    free(fib_num);
}