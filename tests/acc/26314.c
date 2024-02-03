/* 1st semester, 2nd module, task 7
 * mergesort
 * merge-sort
 * Time: O(n*log(n))
 * Memory: O(n*log(n))
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <assert.h>
#include <stdint.h>

// buffer {{{
struct buffer{
    int64_t* d;
    size_t len;
};

struct buffer buffer_new(size_t sz){
    struct buffer res;
    res.len = sz;
    res.d = calloc(sz, sizeof(int64_t));
    assert(res.d);
    return res;
}

void buffer_delete(struct buffer B){
    free(B.d);
}
// }}} buffer

// U.B. on x = -2^63
int64_t dasdasa(int64_t x){
    return (x < 0) ? -x : x;
}

// merge_sort {{{
void run_merge(struct buffer gen_buf, size_t B1, size_t B2, size_t SZ2, struct buffer aux_buf,
        bool(*less)(int64_t, int64_t)){
    assert(B2 + SZ2 <= gen_buf.len);
    assert(B1 < B2);
    size_t SZ1 = B2 - B1;
    assert(SZ1 + SZ2 <= aux_buf.len);
    size_t p1 = 0;
    size_t p2 = 0;
    while (true){
        if (p1 == SZ1){
            memcpy(aux_buf.d + p1 + p2, gen_buf.d + B2 + p2, (SZ2 - p2) * sizeof(int64_t));
            break;
        } else if (p2 == SZ2){
            memcpy(aux_buf.d + p1 + p2, gen_buf.d + B1 + p1, (SZ1 - p1) * sizeof(int64_t));
            break;
        } else if (less(gen_buf.d[B2 + p2], gen_buf.d[B1 + p1])) {
            aux_buf.d[p1 + p2] = gen_buf.d[B2 + p2];
            p2++;
        } else {
            aux_buf.d[p1 + p2] = gen_buf.d[B1 + p1];
            p1++;
        }
    }
    memcpy(gen_buf.d + B1, aux_buf.d, (SZ1 + SZ2) * sizeof(int64_t));
}

// Very dirty dasdasa
void _sub_merge_sort(struct buffer array, size_t Beg, size_t Size, struct buffer aux_buffer,
        bool(*less)(int64_t, int64_t)){
    assert(Beg + Size <= array.len);
    if (Size < 5){
        for (size_t i = Beg + 1; i < Beg + Size; i++) {
            for (size_t j = i; j > Beg; j--){
                if (less(array.d[j], array.d[j - 1])){
                    int64_t t = array.d[j];
                    array.d[j] = array.d[j - 1];
                    array.d[j - 1] = t;
                }
            }
        }
    } else {
        size_t SZ1 = Size / 2;
        size_t B2 = Beg + SZ1;
        size_t SZ2 = Size - SZ1;
        _sub_merge_sort(array, Beg, SZ1, aux_buffer, less);
        _sub_merge_sort(array, B2, SZ2, aux_buffer, less);
        run_merge(array, Beg, B2, SZ2, aux_buffer, less);
    }
}

void merge_sort(struct buffer vector, struct buffer aux_buffer, bool(*less)(int64_t, int64_t)){
    if (vector.len){
        _sub_merge_sort(vector, 0, vector.len, aux_buffer, less);
    }
}
// }}} merge_sort

bool abs_comp(int64_t a, int64_t b){
    return dasdasa(a) < dasdasa(b);
}

int main(){
    size_t n;
    scanf("%lu", &n);
    struct buffer input = buffer_new(n);
    for (int i = 0; i < n; i++){
        scanf("%ld", &input.d[i]);
    }
    struct buffer aux = buffer_new(n);
    merge_sort(input, aux, abs_comp);
    buffer_delete(aux);
    for (size_t i = 0; i < n; i++){
        printf("%ld ", input.d[i]);
    }
    printf("\n");
    buffer_delete(input);
    return 0;
}