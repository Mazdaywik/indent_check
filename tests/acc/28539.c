#include <stdio.h>
int main(void) {
    long n, x0;
    long a;
    long res;
    long res2;
    long f;
    scanf("%ld", &n);
    scanf("%ld", &x0);
    f = n;
    while (n > -1) {
        scanf("%ld", &a);
        if (f == n) {
            res = a;
            res2 = a * n;
        } else {
            res = res * x0 + a;
            if (n > 0) {
                res2 = res2 * x0 + a * n;
            }
        }
        n = n - 1;
    }

    printf("%ld", res);
    printf("\n");
    printf("%ld", res2);

    return (0);
}