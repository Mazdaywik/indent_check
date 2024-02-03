#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
    long long int fl = 0, i, a;
    long long int masfib[92], chfib[92];

    masfib[0] = 1;
    masfib[1] = 2;

    for (i = 2; i < 92; i++) {
        masfib[i] = masfib[i - 1] + masfib[i - 2];
    }

    scanf("%lld", &a);

    if (a == 0) {
        printf("%d", 0);
        return 0;
    }

    for (i = 90; i > -1; i--) {
        if (a >= masfib[i]) {
            a -= masfib[i];
            chfib[i] = 1;
        } else {
            chfib[i] = 0;
        }

        if (chfib[i] == 1 && fl == 0) {
            fl = i;
        }
    }

    for (i = fl; i > -1; i--) {
        printf("%lld", chfib[i]);
    }

    return 0;
}