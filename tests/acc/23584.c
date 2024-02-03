#include <stdio.h>
int main() {
    long long n, x;
    scanf("%Ld", &n);
    scanf("%Ld", &x);
    long long arr[n + 1];
    for (long long i = 0; i <= n; i++) {
        scanf("%Ld", &arr[i]);

    }
    long long s = arr[0];
    for (long long a = 1; a <= n; a++)
        s = s * x + arr[a];

    printf("%Ld\n", s);
    long long sr = arr[0] * n;
    for (long long c = 1; c < n; c++)
        sr = sr * x + arr[c] * (n - c);
    printf("%Ld", sr);
    return 0;
}