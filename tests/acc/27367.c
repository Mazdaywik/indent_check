/* 1st semester, 3rd module
 * zeroxor
 * Time: O(n*log(n))
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>


void swap(void* a, void* b, void* t, size_t width){
    // Such things should be done on stack. That is why people should C++ templates instead of this whatever
    memcpy(t, a, width);
    memcpy(a, b, width);
    memcpy(b, t, width);
}

void min_heap_sift_up(void* base, size_t n, size_t width,
                      bool(*less)(void*, void*, void*), void* guest_less, size_t x){
    assert(x < n && width);
    void* swap_buffer = malloc(width);
    while (x){
        size_t p = (x - 1) >> 1;
        void* x_mem = (uint8_t*)base + width * x;
        void* p_mem = (uint8_t*)base + width * p;
        if (less(x_mem, p_mem, guest_less)){
            swap(x_mem, p_mem, swap_buffer, width);
            x = p;
        } else {
            break;
        }
    }
    free(swap_buffer);
}

void min_heap_sift_down(void* base, size_t n, size_t width,
                        bool(*less)(void*, void*, void*), void* guest_less, size_t x){
    assert(x < n && width);
    void* swap_buffer = malloc(width);
    while (true){
        size_t ch1 = x * 2 + 1;
        if (ch1 >= n){
            break;
        }
        void* x_mem = (uint8_t*)base + width * x;
        uint8_t* ch1_mem = (uint8_t*)base + width * ch1;
        int swp_opt = 0;
        if (ch1 + 1 < n && less(ch1_mem + width, ch1_mem, guest_less)) {
            swp_opt = 1;
        }

        if (less(ch1_mem + width * swp_opt, x_mem, guest_less)){
            swap(ch1_mem + width * swp_opt, x_mem, swap_buffer, width);
            x = ch1 + swp_opt;
        } else {
            break;
        }
    }
    free(swap_buffer);
}

// Time: O(n)
// Third arg of less interface is guest pointer
void build_min_heap(void* base, size_t n, size_t el_width, bool(*less)(void*, void*, void*), void* guest_less){
    assert(base && el_width);
    size_t i = n;
    do {
        i--;
        min_heap_sift_down(base, n, el_width, less, guest_less, i);
    } while (i);
}

// hsort {{{
typedef struct hsort_less_org{
    bool(*less)(void*, void*, void*);
    void* guest_less;
} hsort_less_org;

bool hsort_greater(void* a, void* b, hsort_less_org* guest_ptr){
    return guest_ptr->less(b, a, guest_ptr->guest_less);
}

#define LESSIFY(lf) (bool(*)(void*, void*, void*))(lf)

void hsort(void* base, size_t n, size_t width, bool(*less)(void*, void*, void*), void* guest_less){
    hsort_less_org yyy;
    yyy.less = less;
    yyy.guest_less = guest_less;
    build_min_heap(base, n, width, LESSIFY(hsort_greater), &yyy);
    void *swap_buf = malloc(width);
    for (size_t i = n - 1; i > 0; i--){
        swap(base, (uint8_t*)base + width * i, swap_buf, width);
        min_heap_sift_down(base, i, width, LESSIFY(hsort_greater), &yyy, 0);
    }
    free(swap_buf);
}
// }}} hsort

bool LESS(uint32_t* a, uint32_t* b, void* _u){
    return *a < *b;
}

int main(){
    int n;
    scanf("%d", &n);
    uint32_t* parr = calloc(n + 1, sizeof(uint32_t)); // parr[0] = 0
    for (int i = 0; i < n; i++){
        int32_t Ai;
        scanf("%d", &Ai);
        parr[i + 1] = parr[i]^(*(uint32_t*)&Ai);
    }
    hsort(parr, n + 1, sizeof(uint32_t), LESSIFY(LESS), NULL);
    uint64_t res = 0;
    uint64_t bbeg = 0;
    for (uint64_t i = 1; i <= n + 1; i++){
        if (i > n || parr[i] != parr[i - 1]){
            size_t S = i - bbeg;
            res += S * (S - 1) >> 1;
            bbeg = i;
        }
    }
    printf("%lu\n", res);
    free(parr);
    return 0;
}
