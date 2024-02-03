#include <stdio.h>

int main()
{
    long long n, x0, a;
    scanf("%lld%lld", &n, &x0);
    long arr[n + 1];
    for (long long i = 0; i < n + 1;)
        scanf("%lld", &arr[i++]);
    long long p = arr[0];
    for (long long i = 1; i <= n;++i)
        p = p * x0 + arr[i];
    long long p_dx = n*arr[0];
    long long n1 = n-1;
    for(long long i =1;i<=n-1;++i)
        p_dx=p_dx*x0+arr[i]*n1--;
    printf("%lld %lld", p, p_dx);
}