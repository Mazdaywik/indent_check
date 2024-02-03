#include <stdio.h>

long long poly_val(long long n, long long x0, long long coeffs[]) {
    long long int res = coeffs[0];
    for (int i = 0; i < n - 1; i++) {
        res *= x0;
        res += coeffs[i + 1];
    }
    return res;
}

int main() {
    long long n, x0;
    scanf("%lld %lld", &n, &x0);
    long long coefficients[n + 1];
    for (int i = 0; i <= n; i++)
        scanf("%lld", &coefficients[i]);

    long long d_coefficients[n];
    for (int i = 0; i < n; i++)
        d_coefficients[i] = coefficients[i] * (n - i);

    long long res = poly_val(n + 1, x0,  coefficients);
    long long d_res = poly_val(n, x0, d_coefficients);

    printf("%lld %lld", res, d_res);

    return 0;
}