#include <stdio.h>

struct fraction {
    double a;
    double b;
};

void Kadane_prod(struct fraction *arr, int n) {
    int l = 0, r = 0, start = 0;
    double prod_max = 0, prod = 1;
    for (int i = 0; i < n; i++) {
        prod *= (arr[i].a / arr[i].b);
        if (prod > prod_max) {
            prod_max = prod;
            l = start;
            r = i;
        }
        if (prod < 1) {
            prod = 1;
            start = i + 1;
        }

    }
    printf("%d %d", l, r);
}

int main() {
    int n;
    scanf("%d", &n);
    struct fraction arr[n];
    for (int i = 0; i < n; i++) {
        double a, b;
        char slash;
        scanf("%lf%c%lf", &a, &slash, &b);
        arr[i].a = a;
        arr[i].b = b;
    }
    Kadane_prod(arr, n);
    return 0;
}