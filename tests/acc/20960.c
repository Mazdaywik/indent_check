# include <stdio.h>
# include <math.h>
int main (int argc , char ** argv )
{
    unsigned long long a, b, m, b1, s[64], ans;
    scanf("%lld%lld%lld", &a, &b, &m);
    b1 = b;
    int k;
    for (int i = 0; b1 > 0;i++){
        s[i] = b1%2;
        b1 /= 2;
        k = i;
    }

    ans = a * s[k];
    for (int i = k - 1; i >= 0; i--) {
        ans  = ((ans % m) * 2) % m;
        ans = ans + (((a % m) * s[i]) % m);
    }
    printf("\n\n\n\n%lld", ans % m);
    // printf("%lld", s[0]);
    return 0;
}