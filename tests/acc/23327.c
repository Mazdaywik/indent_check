#include <stdio.h>

long gorner (long n, long x0, long a[]) {
    long res = a[0];
    for (long i = 0; i < n; i++){
        res *= x0;
        res += a[i + 1];
    }
    return res;
}

long derivative (long n, long x0, long a[]){
    long b[n];
    for (long i = 0; i < n; i++){
        b[i] = a[i] * (n - i);
    }
    return gorner ((n - 1), x0, b);
}

long main(){
    long n;
    long x0;
    scanf("%ld%ld", &n, &x0);
    long a[n + 1];
    for (long i = 0; i <= n; ++i) {
        scanf("%ld", &a[i]);
    }
    printf("%ld %ld", gorner(n, x0, a), derivative(n, x0, a));
    return 0;
}