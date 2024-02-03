# include <stdio.h>

int main(){
    long long n, x, ans, proi;
    scanf("%lld %lld %lld", &n, &x, &ans);
    proi = ans * n;
    for (int i = 1; i <= n; ++i){
        long long a;
        scanf("%lld", &a);
        ans = ans * x + a;
        if (i >= n){
            continue;
        }
        proi = proi * x + a * (n-i);
    }
    printf("%lld %lld\n", ans, proi);
    return 0;
}