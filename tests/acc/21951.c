#include <stdio.h>

int main()
{
    long long int n, s, i, x0;
    long long int res, res1;
    scanf("%lld", &n);
    scanf("%lld", &x0);
    n++;
    long long int arr[n];
    for (i = 0; i < n; i++)
        {
        scanf("%lld", &s);
        arr[i] = s;
        }
    res = arr[0];
    for (i = 1; i < n; i++){
        res = (res * x0) + arr[i];
    }
    for (i = 0; i < n; i++){
        arr[i] = arr[i] * (n - i - 1);
    }
    res1 = arr[0];
    for (i = 1; i < n - 1; i++){
        res1 = (res1 * x0) + arr[i];
    }
      
    printf("%lld %lld\n", res, res1);
    return 0;
}