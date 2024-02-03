#include <stdio.h>
long long mulmod(unsigned long long a, unsigned long long b, unsigned long long m)
{
    int i=0;
    int c[63];
for (i=0; i<64; i++)
{
    c[i]=b%2;
    b/=2;
}
unsigned long long res=((a%m)*(c[63]%m))%m;
for (int j=62; j>=0; j--)
{
res=(2*res)%m;
    res=((res%m)+((a%m)*c[j])%m)%m;
}
    return res%m;
}
int main()
{
unsigned long long a, b, m;
scanf("%lld%lld%lld", &a, &b, &m);
if (m == 0)
{
    printf("m can't be equal to zero!!!");
}
else
{
    unsigned long long ans = mulmod(a, b, m);
    printf("%lld", ans);
}
    return 0;
}