#include <stdio.h>

int main() {
    unsigned long long n, kl;
    scanf("%llu", &n);
    unsigned long long  fib[100] = {0};
    unsigned long long  ch = n - 1;
    kl = n;
    fib[0] = 1;
    fib[1] = 1;
    unsigned long long k = 1;
    for (unsigned long long i=2; i<n; i++) {
        if (n - fib[i-2] >= fib[i-1]) {
            fib[i] = fib[i-1] + fib[i-2];
          k = i;
        }
        else {
            break;
        }
    }
    unsigned long long sum_zek[100] = {0};
    sum_zek[0] = 1;
    n = n - fib[k];
    for (int i=k-1; i>0; i--) {
        if ((fib[i] <= n) && (fib[i] != 0) && (sum_zek[k-i-1] != 1)) {
            sum_zek[k-i] = 1;
            n = n - fib[i];
            i -= 1;
        }
    }
  
    char s[100] = {0};
    if (kl > 4) {
        unsigned long long len = 0;
        for (unsigned long long i = 0; i<k; i++) {
            if (sum_zek[i] == 0) {
                s[i] = '0';
            }
            else {
                s[i] = '1';
            }
        }
        printf("%s", s);
    }
    if (kl == 0) {
        printf("0");
    }
    if (kl == 1) {
        printf("1");
    }
    if (kl == 2) {
        printf("10");
    }
    if (kl == 3) {
        printf("100");
    }
    if (kl == 4) {
        printf("101");
    }
    return 0;
}