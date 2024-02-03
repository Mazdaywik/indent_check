#include <stdio.h>
int main(int argc, char **argv)
{
    long n, x0, i, res1, res2;
    scanf("%ld %ld", &n, &x0);
    long a[n];
    for (i = 0; i <= n; i++) {
        scanf("%ld", &a[i]);
    }
    res1 = a[0];
    res2 = a[0] * n;
    for (i = 0; i < n; i++) {
        res1 = res1 * x0 + a[i+1];
    }
    for (i = 0; i < n - 1; i++) {
        res2 = res2 * x0 + a[i+1] * (n-i-1);
    }
    printf("%ld %ld", res1, res2);
    return 0;
}