#include <stdio.h>

int main (int argc , char ** argv )
{
    long n, x0;
    long long res1, res2;
    res1 = 0;
    res2 = 0;
    scanf("%ld", &n);
    scanf("%ld", &x0);
    long a[n + 1];
    for (int i = 0; i < n + 1; i++){
        scanf("%ld", &a[i]);
    }
    for (int i = 0; i < n; i++){
        res1 = (res1 + a[i]) * x0;
    }
    res1 += a[n];
    for (int i = 0; i < n - 1; i++){
        res2 = (res2 + a[i] * (n - i)) * x0;
    }
    res2 += a[n - 1];
    printf("%lld %lld\n", res1, res2);
 return 0;
}