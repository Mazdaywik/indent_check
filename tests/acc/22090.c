#include <stdio.h>

long long int power(long long int base, long long int exponent) {
    long long int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}

int main(void) {
    long long int n;
    scanf("%lli", &n);

    long long int x;
    scanf("%lli", &x);

    long long int arr[n + 1];
    for (long long int k = 0; k <= n; k++) {
        scanf("%lli", &arr[k]);
    }

    long long int P = 0;
    long long int PR = 0;

    for (long long int k = 0; k <= n; k++) {
        P = P + arr[k] * power(x, (n - k));
        if (k < n) {
            PR = PR + arr[k] * (n - k) * power(x, (n - k - 1));
        }
    }

    printf("\n%lli %lli", P, PR);
    return 0;
}
