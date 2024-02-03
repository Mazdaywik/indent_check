#include <stdio.h>

int main() {
    unsigned long long x;
    scanf("%llu", &x);

    if (x == 0) {
        printf("0");
    } 
    else if (x == 1) {
        printf("1");
    } 
    else {
        unsigned long long fib[500] = {0};
        fib[0] = 1;
        fib[1] = 2;
        
        unsigned long long a = fib[0] + fib[1];
        int i = 1;
        while (a <= x) {
            fib[i + 1] = a;
            a += fib[i];
            i++;
        }
        
        int p = i;
         
        unsigned long long res[i+1];
        for(int k=0; k<=i;k++) {
            res[k] = 0;
        }

        while (x != 0) {
            if (fib[i] <= x) {
                res[i] = 1;
                x -= fib[i];
            } 
            else {
                res[i] = 0;
            }
            i--;
        }
        
        for (int j = p; j >= 0; j--) {
            printf("%llu", res[j]);
        }
    }

    return 0;
}