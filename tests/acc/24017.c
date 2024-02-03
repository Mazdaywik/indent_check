#include <stdio.h>

unsigned long long f[93], res[93];

int main(){
    unsigned long long x;
    int stop = 0;
    scanf("%llu", &x);
    if (x == 0){
        printf("%llu ", 0);
        return 0;
    }
    f[0] = 1, f[1] = 1;
    for (int i = 2; i < 93; ++i){
        f[i] = f[i - 2] + f[i - 1];
    }
    for (int i = 0; i < 92; ++i){
        if (x < f[i]){
            stop = i;
            break;
        }
    }
    for (int i = 92; i > 0; --i){
        if (x >= f[i]){
            res[i] = 1;
            x -= f[i];
        }
    }
    for (int i = stop - 1; i >= 1; --i) {
        printf("%llu", res[i]);
    }
    return 0;
}