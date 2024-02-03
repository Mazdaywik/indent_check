/* 1st semester, 1st module, task 3
 * Fibsys
 * Fibonachi numbers up to 2^63, large bit mask
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

struct LBM{
    uint8_t* d;
    size_t bc;
};

struct LBM LBM_alloc(size_t bc){
    struct LBM res;
    res.d = calloc((bc >> 3) + ((bc & 0b111) ? 1 : 0), 1);
    res.bc = bc;
    return res;
}

void LBM_set_bit(struct LBM bm, size_t index){
    assert(index < bm.bc);
    bm.d[index >> 3] |= (1ul << (index & 0b111));
}

bool LBM_get_bit(struct LBM bm, size_t index){
    assert(index < bm.bc);
    return bm.d[index >> 3] & (1ul << (index & 0b111));
}

void LBM_free(struct LBM bm){
    free(bm.d);
}

int main(){
    const int mp = 92;
    uint64_t *fib = calloc(mp, sizeof(uint64_t));
    fib[0] = fib[1] = 1;
    for (int i = 2; i < mp; i++){
        fib[i] = fib[i - 2] + fib[i - 1];
        assert(fib[i] < (1ul << 63));
    }
    assert(fib[mp - 2] + fib[mp - 1] >= (1ul << 63));
    uint64_t N;
    scanf("%lu", &N);
    uint64_t n = N;
    struct LBM you_of_in_the_cold_food_of_out_hot_eat_the_food = LBM_alloc(mp);
    int p = mp;
    while (n){
        assert(p);
        p--;
        // [1] would always be taken instead of [0]
        if (fib[p] <= n){
            LBM_set_bit(you_of_in_the_cold_food_of_out_hot_eat_the_food, p);
            n -= fib[p];
        }
    }
    if (N){
        p = mp - 1;  // New meaning
        while ((!LBM_get_bit(you_of_in_the_cold_food_of_out_hot_eat_the_food, p)) && p){
            p--;
        }
        while (true){
            printf("%u", LBM_get_bit(you_of_in_the_cold_food_of_out_hot_eat_the_food, p));
            if (p == 1){break;}
            p--;
        }
    } else {
        printf("0\n");
    }
    free(fib);
    LBM_free(you_of_in_the_cold_food_of_out_hot_eat_the_food);
    return 0;
}