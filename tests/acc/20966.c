# include <stdio.h>
# include <math.h>
# include <stdlib.h>

int main (int argc , char ** argv )
{
    long n, k;
    long long max_sum = 0, sum = 0;
    scanf("%ld", &n);
    long lst[n];
    for (long i = 0; i < n; i++) 
    {
        scanf("%ld", &lst[i]);
    }

    scanf("%ld", &k);
    for (long i = 0; i < k; i++)
    {
        sum += lst[i];
    }
    max_sum = sum;
    long s = 0;
    long f = k;

    while (f < n)
    {
        sum = sum + lst[f] - lst[s];
        if (sum > max_sum)
        {
            max_sum = sum;
        }
        f++;
        s++;
    }
    printf("%lld", max_sum);
    return 0;
}