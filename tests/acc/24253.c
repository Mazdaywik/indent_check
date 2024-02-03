#include <stdio.h>

int main() {
    unsigned long long a, b, m;
    scanf("%llu %llu %llu", &a, &b, &m);
    unsigned long long answer = 0;
    for (unsigned long long i = 62; ;i--) {
        answer *= 2;
        answer %= m;
        if ((1ull << i) & b) {
            answer += a;
            answer %= m;
        }
        if (i == 0) {
            break;
        }
    }
    printf("%llu\n", answer);
    return 0;
}