#include <stdio.h>

void evalPol(int n, long long *c, long long x0) 
{
    long long Pn = 0;
    long long Pn_prime = 0;
    for (int i = 0; i <= n; ++i) 
    {
        Pn = Pn * x0 + c[i];
        if (i < n)
            Pn_prime = Pn_prime * x0 + c[i] * (n - i);
    }
    printf("%lld ", Pn);
    printf("%lld\n", Pn_prime);
}

int main() 
{
    int n;
    long long x0;
    long long c[100];
    scanf("%d", &n);
    scanf("%lld", &x0);
    for (int i = 0; i <= n; ++i)
        scanf("%lld", &c[i]);
    evalPol(n, c, x0);
    return 0;
}