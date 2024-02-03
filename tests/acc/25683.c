#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

int main(){
    uint64_t a;
    uint64_t b;
    uint64_t m;
    scanf("%lu %lu %lu", &a, &b, &m);
    a %= m;
    uint64_t res = 0;
    for (uint16_t i = 0; i < 64; i++){
        res = (res << 1) % m;
        if (b & (1ul << 63 - i)){
            res = (res + a) % m;
        }
    }
    printf("%lu\n", res);
    return 0;
}