#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main() {
    int n;
    unsigned int k = 1;
    scanf("%d", &n);

    unsigned int a = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a += k << x;
    }

    int m;
    scanf("%d", &m);

    unsigned int b = 0;
    for (int i = 0; i < m; i++) {
        int y;
        scanf("%d", &y);
        b += k << y;
    }

    for (int i = 0; i < 32; i++) {
        if ((a & (k << i)) && (b & (k << i))) {
            printf("%d\n", i);
        }
    }

    return 0;
}