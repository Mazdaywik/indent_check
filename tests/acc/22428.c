#include <stdio.h>

int main(int args, char **argv){
    unsigned long long int a, b, m, res, n = 0;
    scanf("%llu\n%llu\n%llu", &a, &b, &m);
    unsigned long long int binA[63] = { 0 };
    while(b > 0){
        binA[62-n] = b % 2;
        b = b / 2;
        n++;
    }
    for(int i = 0; i < 63; i++){
        if(i != 0){
            if(i != 62){
                res = ((res + ((a % m) * (binA[i]) % m)) % m * (2 % m)) % m;
            }
            else{
                res = (res + ((a % m) * (binA[i] % m)) % m) % m;
            }
        }
        else{
            res = ((((a % m) * (binA[i] % m)) % m) * (2 % m)) % m;
        }
    }
    printf("%llu", res);
    return 0;
}