#include <stdio.h>

int main() {
    unsigned long long a, b, m, result = 0, st = (unsigned long long)1<<63;
    for(scanf("%llu %llu %llu", &a, &b, &m); st; result = (result * 2 % m
                                                         +((a&st)!=0) * b % m) % m,
                                                         st/=2);
    printf("%llu", result);
}