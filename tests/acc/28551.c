#include <stdio.h>

int main() {
    long n, x0;
    scanf("%ld", &n);
    scanf("%ld", &x0);
    long a[n + 1];

    for (int i = 0; i <= n; i++) {
        scanf("%ld", &a[n - i]);
    }

    long px0 = a[n];
    long dpx0 = n * px0;
    int i = n - 1;

    while (i >= 0) {
        px0 = px0 * x0 + a[i];
        i--;
    }

    printf("%ld\n", px0);
    i = n - 1;

    while (i > 0) {
        dpx0 = dpx0 * x0 + a[i] * i;
        i--;
    }

    printf("%ld\n", dpx0);
    return 0;
}