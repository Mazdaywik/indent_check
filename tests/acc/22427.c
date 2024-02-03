#include <stdio.h>

int main(int args, char **argv){
    int n;
    long x0;
    long p = 0;
    long pr = 0;
    scanf("%ld", &n);
    scanf("%ld", &x0);
    for(int i = 0; i <= n; i++){
        long a;
        scanf("%ld", &a);
        if(i != n){
            p = (p + a) * x0;
            if(i != (n - 1)){
                pr = (pr + a * (n - i)) * x0;
            }
            else{
                pr = pr + a;
            }
        }
        else{
            p = p + a;
        }
    }
    printf("%ld ", p);
    printf("%ld", pr);
    return 0;
}