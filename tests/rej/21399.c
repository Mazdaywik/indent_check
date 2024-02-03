# include <stdio.h>
# include <math.h>
int main (int argc , char ** argv )
{
    long long a = 0, b = 0, x, set;
    long long la, lb, bin[330], k;
    scanf("%lld", &la);
    for (long long i = 0; i < la; i++) 
    {
        scanf("%lld", &x);
        a += pow(2, x);
    }
    scanf("%lld", &lb);
    if (lb != 0 & la != 0)
    {
    for (long long i = 0; i < lb; i++) 
    {
        scanf("%lld", &x);
        b += pow(2, x);
    }
    set = a&b;
    if (set != 0)
    {
    for (long long i = 0; set > 0; i++) 
    {
        if (set % 2 == 1) 
        {
            bin[i] = 1;
        }
        else 
        {
            bin[i] = 0;
        }
        set /= 2;
        k = i;
    }
    long long ans[33];
    for (long long i = 0; i < 33; i++) {
        ans[i] = -1;
    }
    // printf("k - %d\n\n", k);
    for (long long i = 0; k >= 0; k--) {
        if (bin[k] == 1) {
            ans[k] = k;
            // printf("k - %d\n", k);
        }
    }

    for (long long i = 0; i < 33; i++) {
        if (ans[i] != -1) {
            printf("%lld ", ans[i]);
        }
    }
    }
    }
    return 0;
}