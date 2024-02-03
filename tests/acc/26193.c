#include <stdio.h>
#include <math.h>
int main(){
    long long mass[1000000], su = 0, cur = 0;
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &mass[i]);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        cur += mass[i];
    }
    su = cur;
    for (int i = k; i < n; ++i){
        cur = cur - (mass[i - k]) + mass[i];
        su = fmax(su, cur);
    }
    su = fmax(su, cur);
    printf("%lld", su);
    return 0;
}