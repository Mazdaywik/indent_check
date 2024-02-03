#include <stdio.h>
#include <limits.h>

unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)) {
    unsigned long l = 0, r = nel - 1, m;

    while (l < r) {
        m = l + (r - l) / 2;

        if (less(m, m + 1)) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }

    return l;
}

int less(unsigned long i, unsigned long j) {
    if (i == j) return 0;

    if (i < j) {
        if (j <= ULONG_MAX) return 1;
        if (i >= ULONG_MAX) return 0;
        return (ULONG_MAX - i) < (j - ULONG_MAX);
    }

    if (i <= ULONG_MAX) return 0;
    if (j >= ULONG_MAX) return 1;
    return (ULONG_MAX - j) < (i - ULONG_MAX);
}

int main() {
    unsigned long arraySize = 13356955260197607378UL;
    unsigned long result = peak(arraySize, less);
    printf("%lu\n", result);
    return 0;
}