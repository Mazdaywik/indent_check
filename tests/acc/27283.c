/* 1st semester, 3rd module
 * merge
 * heap
 * Time: O(N + (N - n) * ln(k))
 * Memory: O(N)
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

void swap_d(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
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

#define LESSIFY(lf) (bool(*)(void*, void*, void*))(lf)

typedef struct {
    int* pointers;
    int** arrays;
} FRESHPLATESLATESLATESLATESLATES;

int plates_ref(FRESHPLATESLATESLATESLATESLATES* sh, int aid){
    return sh->arrays[aid][sh->pointers[aid]];
}

bool LESS(int* a, int* b, FRESHPLATESLATESLATESLATESLATES *sh){
    return plates_ref(sh, *a) < plates_ref(sh, *b);
}

int main(){
    int n;
    scanf("%d", &n);
    assert(n > 0);
    int* Ns = calloc(n, sizeof(int));
    FRESHPLATESLATESLATESLATESLATES share;
    share.arrays = calloc(n, sizeof(int*));
    share.pointers = calloc(n, sizeof(int)); // pointers[i] = 0
    int resulting_size = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &Ns[i]);
        assert(Ns[i] > 0);
        share.arrays[i] = calloc(Ns[i], sizeof(int));
        resulting_size += Ns[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < Ns[i]; j++){
            scanf("%d", &share.arrays[i][j]);
            if (j){
                assert(share.arrays[i][j - 1] <= share.arrays[i][j]);
            }
        }
    }
    int* heap = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++){
        heap[i] = i;
    }
    build_min_heap(heap, n, sizeof(int), LESSIFY(&LESS), &share);
    int* result = calloc(resulting_size, sizeof(int));
    int active_arrays = n;
    for (int s = 0; s < resulting_size; s++){
        assert(active_arrays);
        int best_arr_id = heap[0];
        result[s] = plates_ref(&share, best_arr_id);
        share.pointers[best_arr_id]++;  // Here, I am changing only resulting value of ONE index in heap, the top
        // Now I can sift down the minimum, or (if end of best array is reached), I can wipe out old minimum
        // To the end and forget about it
        if (share.pointers[best_arr_id] == Ns[best_arr_id]){
            active_arrays--;
            if (active_arrays){
                swap_d(&heap[0], &heap[active_arrays]);
                min_heap_sift_down(heap, active_arrays, sizeof(int), LESSIFY(&LESS), &share, 0);
            }
        } else {
            min_heap_sift_down(heap, active_arrays, sizeof(int), LESSIFY(&LESS), &share, 0);
        }
    }
    for (int i = 0; i < resulting_size; i++){
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    free(share.pointers);
    free(heap);
    for (int i = 0; i < n; i++){
        free(share.arrays[i]);
    }
    free(share.arrays);
    free(Ns);
}