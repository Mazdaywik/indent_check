#include <stdio.h>
long long gor(unsigned int n, long long x, long long* a)
{
long long result=0;
for (unsigned int i=0; i<=n; i++)
    {
    result=result*x+a[i];
    }
return result;
}

long long der_of_gor(unsigned int n, long long x, long long* a)
{
    long long result=0;
    for (unsigned int i=0; i<n; i++)
    {
        result = result*x+a[i]*(n-i);
    }
    return result;
}
int main()
{
    unsigned int n;
    long long x;
    scanf("%u%lld", &n, &x);
    long long a[n+1];
    for (unsigned int i=0; i<=n; i++)
    {
        scanf("%lld", &a[i]);
    }
    long long result=gor(n, x, a);
    long long der_result=der_of_gor(n, x, a);
    printf("%lld %lld\n", result, der_result);
    return 0;
}