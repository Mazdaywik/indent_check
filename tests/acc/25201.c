#include <stdio.h>

int main( void ){
    long long n, x0;
    scanf("%lld %lld", &n, &x0);
    long long current, def = 0, der = 0;
    
    for (long long i = n; i >= 1; i--){
        scanf("%lld", &current);
        def = (def + current) * x0;
        der = der * x0 + (current * i);
    }
    scanf("%lld", &current);
    def = def + current;
    printf("%lld %lld", def, der);
}