#include <stdio.h>

int main() {
    long n, k;
    scanf("%ld", &n);

    long a[n];

    for (long i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }

    scanf("%ld", &k);

    long summa = 0;
    long j = 0;

    while (j < k && j < n) {
        summa += a[j];
        j++;
    }

    long max_summ = summa;

    long l = k;
    while (l < n) {
        summa += a[l] - a[l - k];

        if (summa > max_summ) {
            max_summ = summa;
        }
        l++;
    }

    printf("%ld\n", max_summ);
    return 0;
}