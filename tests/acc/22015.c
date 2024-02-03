#include <stdio.h>
#include <math.h>

void dec_to_bin(unsigned long long dec, int* bin) {
    int i = 0;
 
    while(dec > 0){
        bin[i] = dec % 2;
        dec /= 2;
        i++;
    }

    while(i < 64){
        bin[i] = 0;
        i++;
    }
}

int main(void){
    unsigned long long a, b, m, result;
    int bin[64], length, i;
    
    scanf("%llu %llu %llu", &a, &b, &m);
    dec_to_bin(b, bin);
    
    result = ((a % m) * (bin[63] % m)) % m;

    for(int j = 62; j >= 0; j--){
//        printf("%d", bin[j]);
        result = (result * 2) % m;
        result = ((result % m) + ((a % m) * bin[j]) % m) % m;
    }

    
    result %= m;
    printf("%llu", result);
    return 0;
}