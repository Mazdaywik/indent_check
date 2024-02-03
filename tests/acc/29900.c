#include <stdio.h>
#include <stdlib.h>

long long proced(long long n, long long x0, long long deriv[]) {
    long long int result = deriv[0];
    for (int i = 0; i < n - 1; i++) {
        result *= x0;
        result += deriv[i + 1];
    }
    return result;
}

int main() {
    long long n, x0;
    scanf("%lld %lld", &n, &x0);
    long long derivs[n + 1];
    for (int i = 0; i <= n; i++)
        scanf("%lld", &derivs[i]);
    long long derivsd[n];
    for (int i = 0; i < n; i++)
        derivsd[i] = derivs[i] * (n - i);
    long long result = proced(n + 1, x0,  derivs);
    long long resd = proced(n, x0, derivsd);
    printf("%lld ", result); 
	printf("%lld\n", resd);
    return 0;
}