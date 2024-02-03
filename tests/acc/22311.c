#include <stdio.h>
#include <math.h>

int main() {
    long long int a, b;
    int len_a, len_b;
    a = 0;
    b = 0;
    scanf("%d", &len_a);
    for (int i = 0; i < len_a; i++) {
        int x;
        scanf("%d", &x);
        a += pow(2, x);
    }

    scanf("%d", &len_b);
    for (int j = 0; j < len_b; j++) {
        int x;
        scanf("%d", &x);
        b += pow(2, x);
    }

    long int res = a & b;
    int i = 0;
    while (res > 0) {
        if (res % 2 == 1)
            printf("%d ", i);
        res /= 2;
        i++;

    }

    return 0;
}