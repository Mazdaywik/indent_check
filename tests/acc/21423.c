#include <stdio.h>

int main(int argc, char **argv)
{
    int n;
    long long int x;
    scanf("%d", &n);
    scanf("%lld", &x);

    long long int a[n];
    for (int k = 0; k <= n; k++) 
        scanf("%lld", &a[k]);

    long long int polynom = a[0];
    for (int i = 1; i <= n; i++)
        polynom = polynom * x + a[i];

    printf("%lld ", polynom);
    
    long long int d_polynom = a[0] * n;
    for (int j = 1; j < n; j++)
        d_polynom = (d_polynom * x) + (a[j] * (n - j));
    
    printf("%lld\n", d_polynom);

    return 0;
}