#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    double *arr = malloc(sizeof(double) * n);
    int index_max;
    double frac_max = 0.0;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d/%d", &a, &b);
        double frac = 1.0 * a / b;
        arr[i] = frac;
        if (frac > frac_max) {
            frac_max = frac;
            index_max = i;
        }
    }
    if (frac_max <= 1.0)
        printf("%d %d\n", index_max, index_max);
    else {
        int l = 0, r = 0, start = 0, i = 0;
        double maxprod = arr[0], prod = 1.0;
        while (i < n)
        {
            prod *= arr[i];
            if (prod > maxprod) {
                maxprod = prod;
                l = start;
                r = i;
            }
            i++;
            if (prod < 1.0) {
                prod = 1.0;
                start = i;
            }
        }
        printf("%d %d\n", l, r);
    }
    free(arr);
    return 0;
}