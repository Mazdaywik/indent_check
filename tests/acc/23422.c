#include <stdio.h>

struct pair{
    long long first, second;
};

void polynom(long long num, long long x0, struct pair *res, long long k){
    scanf("%lld", &k);
    res->first = res->first * x0 + k;
    if (num == 0)
        return ;
    res->second = res->second * x0 + k * num;
    polynom(num - 1, x0, res, k);
}

int main() {
    long long num, x0;
    struct pair p;
    p.first = 0;
    p.second = 0;
    scanf("%lld%lld", &num, &x0);
    polynom(num, x0, &p, 0);
    printf("%lld %lld", p.first, p.second);
    return 0;
}