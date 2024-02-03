#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    double maxProd = 0.0, currProd = 1.0;
    int l = 0, r = 0, start = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d/%d", &a, &b);
        double value = (double)a / b;
        currProd *= value;

        if (currProd > maxProd) {
            maxProd = currProd;
            l = start;
            r = i;
        }

        if (currProd < 1.0) {
            currProd = 1.0;
            start = i + 1;
        }
    }

    printf("%d %d", l, r);
    return 0;
}