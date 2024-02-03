#include <stdio.h>

void ans(int n, long long int x, long long int result, long long int result1) {
    if(n == -1){
        printf("%lld\n", result);
        printf("%lld\n", result1);
        return;
    }
    long long int poly;
    scanf("%lld", &poly);
    result = result * x + poly;
    if(n) result1 = result1 * x + poly * n;
    ans(n-1, x,  result, result1);
}

int main() {
    int n;
    long long int x0;
    scanf("%d %lld", &n, &x0);
    ans(n, x0, 0, 0);
    return 0;
}