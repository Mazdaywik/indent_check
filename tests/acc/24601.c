#include <stdio.h>

unsigned long long max_fib(long long x, int need_number){ // 1 - number, 0 - index
    unsigned long long i = 0, n_last = 0, n_now = 1, n_mid;

    while(n_now <= x){
        n_mid = n_now;
        n_now =  n_now + n_last;
        n_last = n_mid;
        i++;
    }

    if (need_number == 1)
        return n_last;
    else
        return --i;
}

int main(void){
    long long x;

    scanf("%lld", &x);

    if (x == 0 || x == 1)  {
        printf("%lld", x);
    } 

    else {
        long long n, pos, max_pos;

        max_pos = max_fib(x, 0);
        
        long long result[max_pos];

        for(int i = 0; i < max_pos - 1; i ++)
            result[i] = 0;
        
        result[max_pos - 1] = 1;

        while(x > 0){
            n = max_fib(x, 1);
            pos = max_fib(x, 0);
            result[pos - 1] = 1;
            x -= n;
        }

        for(int i = max_pos - 1; i >= 0; i--)
            printf("%lld", result[i]);
    }

    return 0;
}