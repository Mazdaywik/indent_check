#include <stdio.h>

int main()
{
    long long n, x0, pol = 0, proizv = 0;
    scanf("%lld %lld", &n, &x0);
    long long an[100];



    for (int i = 0; i <= n; i++)
    {
        scanf("%lld", &an[i]);
    }


    pol = an[0];
    
    for (int i = 0; i < n; i++) 
    {
        pol = pol * x0 + an[i+1];

        if (i < n-1)
        {
            proizv = (proizv + (n-i) * an[i]) * x0;
        }
        else 
        {
            proizv = proizv + an[i] * (n-i);
        }
    }

    printf("%lld %lld\n", pol, proizv);

    return 0;
}