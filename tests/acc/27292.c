/* 1st semester, 3rd module
 * cluster
 * heap
 * Time: O(M * log(N))
 * Memory: O(N + M)
 * (man, I really felt those EGE vibes again. I feel like I resolved this task again and again for millennia)
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

int64_t max_ld(int64_t a, int64_t b){
    return (a > b) ? a : b;
}

void swap(void* a, void* b, void* t, size_t width){
    // Such things should be done on stack. That is why people should C++ templates instead of this whatever
    memcpy(t, a, width);
    memcpy(a, b, width);
    memcpy(b, t, width);
}

void swap_ld(int64_t *a, int64_t *b){
    int64_t t = *a;
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

bool LESS(int64_t* a, int64_t* b, void* _u){
    return *a < *b;
}

typedef struct{
    int t1, t2;
} pair;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    assert(N && M);
    pair *arr = calloc(M, sizeof(pair));
    for (int i = 0; i < M; i++){
        scanf("%d %d", &arr[i].t1, &arr[i].t2);
    }
    int64_t* heap = calloc(N, sizeof(int64_t));
    int load = 0;
    int64_t reach = 0;
    for (int i = 0; i < M; i++){
        if (load == N){
            reach = heap[0];  // Took out the nearest
            load--;
            if (load){
                swap_ld(&heap[0], &heap[load]);
                min_heap_sift_down(heap, load, sizeof(int64_t), LESSIFY(&LESS), NULL, 0);
            }
        }
        heap[load] = max_ld(reach, arr[i].t1) + arr[i].t2;
        load++;
        min_heap_sift_up(heap, load, sizeof(int64_t), LESSIFY(&LESS), NULL, load - 1);
    }
    for (int i = 0; i < load; i++){
        reach = max_ld(reach, heap[i]);
    }
    printf("%ld\n", reach);
    free(heap);
    free(arr);
    return 0;
}