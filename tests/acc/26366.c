/* 1st semester, 2nd module, task 8
 * quicksort
 * unstable quicksort, random number generation, swap
 * Time: O(n^2) worst, O(n*log(n)) average
 * Memory: O(n)
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef uint8_t byte;

void swap_ul(uint64_t* a, uint64_t* b){
    uint64_t t = *a;
    *a = *b;
    *b = t;
}

void swap(void* a, void* b, void* t, size_t width){
    memcpy(t, a, width);
    memcpy(a, b, width);
    memcpy(b, t, width);
}

// a and b are indexes
void swap_in_buff(byte* base, size_t a, size_t b, void* t, size_t width){
    swap(base + a * width, base + b * width, t, width);
}

// quick_sort {{{
size_t quick_sort_prepare_delimiter(byte* base, size_t n, size_t elw,
                                  bool(*less)(void*, void*, void*), void* guest_less, void* swap_buffer){
    size_t q = (((size_t)rand() << 32) + rand()) % n;
//    printf("SubArray: ");
//    for (int i = 0; i < n; i++){
//        printf("%d ", *((int*)_base + i));
//    }
//    printf("q: %lu\n", q);
    size_t p1 = 0;
    size_t p2 = n - 1;
    while (true){
        while (p1 < q && !less(base + q * elw, base + p1 * elw, guest_less)){
            p1++;
        }
        while (p2 > q && !less(base + p2 * elw, base + q * elw, guest_less)){
            p2--;
        }
        if (p1 == p2){
            break;
        } else if (p1 == q){
            swap_in_buff(base, q, p2, swap_buffer, elw);
            q = p2;
        } else if (p2 == q){
            swap_in_buff(base, p1, q, swap_buffer, elw);
            q = p1;
        } else {
            swap_in_buff(base, p1, p2, swap_buffer, elw);
        }
    }
    return q;
}

// With tail recursion optimization
// If n is zero, base can be whatever you want it to be
void quick_sort_sub(byte* base, size_t n, size_t elw, size_t m,
                bool(*less)(void*, void*, void*), void* guest_less, void* swap_buffer){
    if (!base || !elw){
        return;
    }
    while (n >= m){
        size_t q = quick_sort_prepare_delimiter(base, n, elw, less, guest_less, swap_buffer);
        byte* base_left = base;
        size_t size_left = q;
        byte* base_right = base + (q + 1) * elw;
        size_t size_right = n - q - 1;
        if (base_right < base_left){
            swap_ul((uint64_t*)&base_left, (uint64_t*)&base_right);
            swap_ul(&size_left, &size_right);
        }
        quick_sort_sub(base_left, size_left, elw, m, less, guest_less, swap_buffer);
        base = base_right;
        n = size_right;
    }
    if (n){
        // Selection is unstable
        // insertion is stable (but quicksort is unstable by it's nature, so I'm using selection)
        for (size_t i = 0; i < n; i++){
            uint8_t* min = base + i * elw;
            for (size_t j = i + 1; j < n; j++){
                if (less(base + j * elw, min, guest_less)){
                    min = base + j * elw;
                }
            }
            swap(base + i * elw, min, swap_buffer, elw);
        }
    }
}

void quick_sort(void *base, size_t n, size_t elw, size_t m, bool(*less)(void*, void*, void*), void* guest_less){
    if (m < 2){
        m = 2;
    }
    void* swap_buffer = malloc(elw);
    quick_sort_sub(base, n, elw, m, less, guest_less, swap_buffer);
    free(swap_buffer);
}
// }}} quick_sort

bool my_comp(void* a, void* b, void* _u){
//    return abs(*(int*)a) < abs(*(int*)b);
    return *(int*)a < *(int*)b;
}

int main(){
    srand(time(NULL));
    size_t n, m;
    scanf("%lu %lu", &n, &m);
    int* arr = calloc(n, sizeof(int));
    for (size_t i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, n, sizeof(int), m, my_comp, NULL);
    for (size_t i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}