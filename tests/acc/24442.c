#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, char ** argv) 
{
    int n;
    scanf("%d", &n);
    int lst[n], sum, is_include, c, is_power2, ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &lst[i]);
    }
    long n1 = 1, i1;
    while (n > 0)
    {
        n1 *= 2;
        n--;
    }
    for (long i = 1; i < n1; i++)
    {
        sum = 0;
        is_power2 = 1;
        c = 0;
        i1 = i;
        while (i1 > 0)
        {
            is_include = i1 % 2;
            if (is_include)
            {
                sum += lst[c];
            }
            c++;
            i1/= 2;
        }
        // printf("%d ", sum);
        if (sum <= 0)
            is_power2 = 0;
        while (sum > 1)
        {
            if (sum % 2 == 1)
                is_power2 = 0;
            sum /= 2;
        }
        ans += is_power2;
        // printf("%d\n", is_power2);
    }
    printf("%d", ans);
    return 0;
}