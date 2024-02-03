# include <stdio.h>
# include <math.h>

int main (int argc , char ** argv )
{
    long long n;
    int ans[100];
    scanf("%lld", &n);
    if (n == 0)
    {
        printf("0");
    }
    else
    {
        long long lst[100];
        lst[0] = 1;
        lst[1] = 2;
        for (int i=2; i < 100; i++) 
        {
            lst[i] = lst[i-1] + lst[i-2];
            // printf("%lld\n", lst[i]);
        }
        int i = 0;
        while (n >= lst[i]) 
        {
            i++;
        }
        i--;
        int ind = 0;
        while (i >= 0) 
        {
            if (lst[i] <= n) 
            {
                // ans++;
                ans[ind] = 1;
                n -= lst[i];
                // printf("%d ", lst[i]);
            }
            else
            {
                ans[ind] = 0;
            }
            ind++;
            i--;
        }
        for (int i = 0; i < ind; i++)
        {
            printf("%d", ans[i]);
        }
    }

    return 0;
}