#include <stdio.h>

unsigned long long mass[64];

int main(){
    unsigned long long a, b, m, ans;
    scanf("%llu %llu %llu", &a, &b, &m);
    int i = 63;
    while (b > 0){
        mass[i] = (b % 2) * a;
        b /= 2;
        i -= 1;
    }
    ans = 0;
    for (int i = 0; i < 64; ++i){
        ans = ((ans * 2) % m + (mass[i] % m)) % m;
    }
    ans = ans % m;
    printf("%llu", ans);
    return 0;
}