#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);
    long a[n];
    for (int i = 0; i < n; i++) 
    {
    scanf("%ld", &a[i]);
    }
    int k;
    scanf("%d", &k);
    long sum = 0;
    for (int i = 0; i < k; i++) 
    {
    sum += a[i];
    }
    int l = 0, m = k;
    long max = sum;
    while (m < n) 
    {
        sum += (a[m] - a[l]);
        if (sum > max) 
        {
        max = sum;
        }
        m++;
        l++;
    }
    printf("%ld", max);
    return 0;
}