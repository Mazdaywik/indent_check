#include <stdio.h>
#include <inttypes.h>

int64_t polynom(int64_t koef[], int n, int64_t x0) {
    int64_t res = koef[0];
    for (int i = 1; i <= n; i++) {
        res = res * x0 + koef[i];
    }
    return res;
}

int64_t polynompr(int64_t koef[], int n, int64_t x0) {
    int64_t respr = koef[0] * n;
    for (int i = 1; i < n; i++) {
        respr = respr * x0 + koef[i] * (n - i);
    }
    return respr;
}

int main() {
    int n;
    scanf("%d", &n);
    int64_t koef[n + 1], x0;
    scanf("%"SCNd64, &x0);
    int64_t x01 = x0;

    // Ввод коэффициентов полинома
    for (int i = 0; i <= n; i++) {
        scanf("%"SCNd64, &koef[i]);
    }

    printf("%"PRId64"\n%"PRId64, polynom(koef, n, x0), polynompr(koef, n, x01));
    return 0;
}