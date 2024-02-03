#include <stdio.h>

int main()
{
    long n;
    scanf("%ld", &n);
    if (n > 1000000)
        return 1;
    long a[n];
    for (long i = 0; i < n; i++)
        scanf("%ld", &a[i]);
    long k;
    scanf("%ld", &k);
    if (k > n)
        return 1;
    long res = 0;
    long sum = 0;
    for (long i = 0; i < k; i++)
        sum += a[i];
    if (k == n)
    {
        printf("%ld", sum);
        return 0;
    }
    long i = 0;
    while (k <= n)
    {
        if (sum > res)
            res = sum;
        sum = sum - a[i] + a[k];
        i++;
        k++;
    }
    printf("%ld", res);
    return 0;
}