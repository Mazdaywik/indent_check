# include <stdio.h>
# include <math.h>
int main (int argc , char ** argv )
{
    long long n, x, xn;
    long long ans = 0, ans2 = 0;
    scanf("%lld", &n);
    scanf("%lld", &x);
    if (n > 0) {
        scanf("%lld", &xn);
        ans = xn;
        if (n == 0)
        {
            ans2 = 1;
        }
        else
        {
            ans2 = xn * n;
        }
        // printf("ans - %lld ans2 - %lld\n", ans, ans2);
        for (long long i = 0; i < n; i++) {
            scanf("%lld", &xn);
            ans = (ans * x) + xn;
            if (i < n - 1)
            {
                ans2 = (ans2 * x) + (n - i - 1) * xn;
            }
            // printf("ans - %d ans2 - %d\n", ans, ans2);
        }
        printf("%lld %lld\n", ans, ans2);
    } 
    else {
        scanf("%lld", &xn);
        printf("%lld 1", xn);
    }
    return 0;
}

// # include <stdio.h>
// # include <math.h>

// int main (int argc , char ** argv )
// {
//     long long n;
//     int ans[100];
//     scanf("%lld", &n);
//     if (n == 0)
//     {
//         printf("0");
//     }
//     else
//     {
//     long long lst[100];
//     lst[0] = 1;
//     lst[1] = 2;
//     for (int i=2; i < 100; i++) {
//         lst[i] = lst[i-1] + lst[i-2];
//         // printf("%lld\n", lst[i]);
//     }
//     int i = 0;
//     while (n >= lst[i]) {
//         i++;
//     }
//     i--;
//     int ind = 0;
//     while (i >= 0) {
//         if (lst[i] <= n) {
//             // ans++;
//             ans[ind] = 1;
//             n -= lst[i];
//             // printf("%d ", lst[i]);
//         }
//         else
//         {
//             ans[ind] = 0;
//         }
//         ind++;
//         i--;
//     }
//     for (int i = 0; i < ind; i++)
//     {
//         printf("%d", ans[i]);
//     }
//     }

//     return 0;
// }