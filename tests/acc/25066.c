#include<stdio.h>
int main(){
    long n, coef, x;
    scanf("%ld %ld %ld", &n, &x, &coef);
    long res = coef, res_dx = coef*n;
    for (int i = 0; i < n; i++){
        res *= x;
        scanf("%ld", &coef);
        res += coef;
        if (i != n - 1){
            res_dx *= x;
            res_dx += coef * (n - i - 1);
        }
    }
    printf("%ld %ld", res, res_dx);
}