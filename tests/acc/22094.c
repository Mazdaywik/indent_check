#include <stdio.h>
#include <math.h>
int main (int argc , char ** argv){
    unsigned long long x, f1, f2, f3, ans, max1, i;
    scanf("%llu", &x);
    f1 = 1;
    f2 = 1;
    f3 = 0;
    ans = 0;
    max1 = 0;
    int a[100];
    for (int i = 0; i < 100; i++){
        a[i] = 0;
    }
    while (x > 0){
        i = 0;
        while (f3 <= x){
            if (x == 1){
                i = 1;
                f1 = 1;
                f3 = 2;
            }
            else{
                if (x == 2){
                    i = 2;
                    f1 = 2;
                    f3 = 3;
                }
                else{
                    if (((1ULL << 63) - f2) >= f1){
                        f3 = f1 + f2;
                        f1 = f2;
                        f2 = f3;
                        i += 1;
                    }
                    else{
                        f1 = f2;
                        i += 1;
                    }

                }
            }
            }
        i = i - 1;
        if (i > max1){
            max1 = i;
        }
        a[i] = 1;
        x = x - f1;
        f1 = 1;
        f2 = 1;
        f3 = 0;    
    }
    for (int i = 0; i <= max1; i++){
        printf("%d", a[max1 - i]);
    } 
}