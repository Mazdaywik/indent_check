#include <stdio.h>

long long polynom(long long n, long long x, long long arr[])
{
    long long i, s = arr[0];
    for(i = 1; i < (n + 1); i++) s = x*s + arr[i];
    return s;
}

long long determ(long long n, long long x, long long arr[])
{
    long long i, s = arr[0]*n;
    for(i = 1; i < n; i++) s = s*x + arr[i]*(n-i);
    return s;
}


int main(int argc, char **argv)
{
    long long n, x, i;
    scanf("%lld %lld", &n, &x);
    
    long long arr[n+1];
    for (i = 0; i < (n + 1); i++) scanf("%lld", &arr[i]);
    
    printf("%lld %lld\n", polynom(n, x, arr), determ(n, x, arr));
    return 0;
}
