#include <stdio.h>
#include <math.h>

int main() {
    unsigned long long n, sum = 0, count = 0, k;
    
    scanf("%llu", &n);

    unsigned long long arr[n+1];

    for (int i = 0; i < n; i++) {
        scanf("%llu", &arr[i]);
    }
    
    unsigned long a = 1 << n;
    for (int i = 1; i < a; i++) {
        k = i;
        for (int j = 0; j < n; j++) {
            if (k & 1) {
                sum += arr[j];
            }
            k >>= 1;
        }

        while ((sum != 0) && (sum % 2 == 0)) {
            sum /= 2;
        }

        if (sum == 1) {
            count++;
        }

        sum = 0;
    }

    printf("%llu", count);

    return 0;
}