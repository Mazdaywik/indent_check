#include <stdio.h>

int main() {
    long long n, x0;
    scanf("%lld", &n);
    scanf("%lld", &x0);

    long long coefs[n];
    for(int i = 0; i <= n; i++) {
        scanf("%lld", &coefs[i]);
    }

    long long now = coefs[0] * x0 + coefs[1];
    long long now_pr = coefs[0] * n * x0 + coefs[1] * (n - 1);

    for (int i = 2; i <= n; i++) {
        now *= x0;
        now += coefs[i];
    }

    for (int i = 2; i <= n - 1; i++) {
        now_pr *= x0;
        now_pr += coefs[i] * (n - i);
    }

    printf("%lld %lld\n", now, now_pr);
    
    return 0;
}
