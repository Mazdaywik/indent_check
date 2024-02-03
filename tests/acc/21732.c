#include <stdio.h>
#include <math.h>


int main(int argc, char **argv)
{
    long long int n, x0, coef, pol, i, pr;
    scanf("%lld%lld%lld", &n, &x0, &coef);
    pol = coef;
    pr = coef * n;

    for (i = 0; i < n; i++) {
        scanf("%lld", &coef);
        pr = (i - n + 1 == 0) ? pr : (pr *x0);
        pr += (n - i - 1) * coef;

        pol *= x0;
        pol += coef;
    }
    printf("%lld %lld", pol, pr);

    return 0;
}
