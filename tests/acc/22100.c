#include <stdio.h>

int main() 
{
    long n, x0, kf;
    scanf("%ld%ld%ld", &n, &x0, &kf);
    long long pol = kf;
    long long pr = kf*n;
    for (long i = 1; i <= n; i++) {
        scanf("%ld", &kf);
        pol = pol * x0 + kf;
        if (i < n) pr = pr * x0 + kf*(n - i);
    }
    printf("%lld\n", pol);
    printf("%lld\n", pr);
    return 0;
}