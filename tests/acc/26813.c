#include <stdio.h>

void evaluatePolynomial(long int n, long int x0, long int coefficients[], long int *result, long int *derivative) {
    *result = coefficients[0];
    *derivative = coefficients[0] * n;

    for (int i = 1; i <= n; ++i) {
        *result = *result * x0 + coefficients[i];
        if(n - i){
            *derivative = *derivative * x0 + coefficients[i] * (n - i);}
    }
}

int main() {
    long int n, x0;
    scanf("%ld", &n);
    scanf("%ld", &x0);

    long int coefficients[n + 1];
    for (int i = 0; i <= n; ++i) {
        scanf("%ld", &coefficients[i]);
    }

    long int result, derivative;
    evaluatePolynomial(n, x0, coefficients, &result, &derivative);

    printf("%ld\n", result);
    printf("%ld\n", derivative);

    return 0;
}
