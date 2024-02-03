#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long x0;
    scanf("%lld", &x0);
    long long p[n + 1];
    for (int i = 0; i <= n; i += 1) {
        scanf("%lld", &p[i]);
    }
    long long answer1 = p[0];
    for (int i = 1; i <= n; i++) {
        answer1 *= x0;
        answer1 += p[i];
    }
    long long answer2 = p[0] * n;
    for (int i = 1; i < n; i++) {
        answer2 *= x0;
        answer2 += p[i] * (n - i);
    }
    printf("%lld %lld\n", answer1, answer2);
}