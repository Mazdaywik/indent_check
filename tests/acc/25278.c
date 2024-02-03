#include<stdio.h>
int main(){
    unsigned long a, b, m;
    int bin[64];
    scanf("%ld %ld %ld", &a, &b, &m);
    for (int i = 63; i >= 0; i--){
        bin[i] = b % 2;
        b >>= 1;
    }
    a = a % m;
    unsigned long res = bin[0] * a;
    for (int i = 1; i < 64; i++){
        res = ((res % m) * 2 + a * bin[i]) % m;
    }
    printf("%ld", res);
}