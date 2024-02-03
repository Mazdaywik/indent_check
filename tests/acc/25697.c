/* 1st semester, 1st module, task 3
 * Fibsys
 * Fibonachi numbers up to 2^63, large bit mask
 * Time: O(2^(n/2)*log(n*A)*n)
 * Memory: O(e + 2^(n/2))
 * Misery: O(BusyBeaver(n*999))
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

// Large Bit Mask (like... REALLY large, for real)
struct LBM{
    uint8_t* d;
    size_t bc;
};

struct LBM LBM_alloc(size_t bc){
    struct LBM res;
    res.d = calloc((bc >> 3) + (bc & 0b111) ? 1 : 0, 8);
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
    struct LBM setA = LBM_alloc(32);
    struct LBM res = LBM_alloc(32);
    uint32_t as;
    scanf("%u", &as);
    for (int j = 0; j < as; j++){
        uint32_t iv;
        scanf("%u", &iv);
        assert(iv < 32);
        LBM_set_bit(setA, iv);
    }
    uint32_t bs;
    scanf("%u", &bs);
    for (int j = 0; j < bs; j++){
        uint32_t iv;
        scanf("%u", &iv);
        assert(iv < 32);
        if (LBM_get_bit(setA, iv)){
            LBM_set_bit(res, iv);
        }
    }
    LBM_free(setA);
    for (int i = 0; i < 32; i++) {
        if (LBM_get_bit(res, i)){
            printf("%d ", i);
        }
    }
    printf("\n");
    LBM_free(res);
}
