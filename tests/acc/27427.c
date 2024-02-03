/* 1st semester, 3rd module
 * qsstack
 * stack, quick-sort
 * */
// TODO: debug
// 5
// 5 4 3 2 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    size_t beg, sz;
} QSTask;

void swap_qst(QSTask* a, QSTask* b){
    QSTask t = *a;
    *a = *b;
    *b = t;
}

// vector {{{
typedef QSTask vecT;
typedef struct {
    vecT* data;
    size_t len;
    size_t allocated;
} vector;

vector VEC_new(){
    vector res;
    res.data = NULL;
    res.len = 0;
    res.allocated = 0;
    return res;
}

void VEC_delete(vector* this){
    free(this->data);
}

void VEC_ensure_allocation(vector* this, size_t v){
    if (this->allocated >= v){
        return;
    }
    if (this->allocated){
        size_t new_sz = this->allocated;
        while (new_sz < v){
            new_sz <<= 1;
        }
        vecT *new_block = calloc(new_sz, sizeof(vecT));
        memcpy(new_block, this->data, this->len * sizeof(vecT));  // Lmao
        free(this->data);
        this->allocated = new_sz;
        this->data = new_block;
    } else {
        this->allocated = v;
        this->data = calloc(v, sizeof(vecT));
    }
}

// New elements are zeroes
void VEC_ensure_len(vector* this, size_t len){
    VEC_ensure_allocation(this, len);
    if (len > this->len){
        this->len = len;
    }
}

void VEC_push_back(vector* this, vecT v){
    VEC_ensure_len(this, this->len + 1);
    this->data[this->len - 1] = v;
}

vecT VEC_pop_back(vector* this){
    assert(this->len);
    vecT val = this->data[this->len - 1];
    this->len--;
    return val;
}
// }}} vector

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

void quick_sort_get_task_and_continue(byte* global_base, size_t elw,
                    bool(*less)(void*, void*, void*), void* guest_less, void* swap_buffer,
                    vector* task_stack){
    assert(task_stack->len);
    QSTask tsk = VEC_pop_back(task_stack);
    while (true){
        if (!tsk.sz){
            break;
        }
        byte* base = global_base + tsk.beg * elw;
        size_t n = tsk.sz;
        if (n < 10){
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
            break;
        } else {
            size_t q = quick_sort_prepare_delimiter(base, n, elw, less, guest_less, swap_buffer);
            QSTask task_left;
            task_left.beg = tsk.beg + 0;
            task_left.sz = q;
            QSTask task_right;
            task_right.beg = tsk.beg + q + 1;
            task_right.sz = n - q - 1;
            if (task_right.sz < task_left.sz){
                swap_qst(&task_left, &task_right);
            }
            // left is smol (like a 1/2yo eepy kitten)
            VEC_push_back(task_stack, task_left);
            // right is big (like a hippopotamus in my trailer)
            tsk = task_right;
        }
    }
}

void quick_sort(void *base, size_t n, size_t elw, bool(*less)(void*, void*, void*), void* guest_less){
    assert(base && elw);
    vector task_stack = VEC_new();
    QSTask igniter;
    igniter.beg = 0;
    igniter.sz = n;
    VEC_push_back(&task_stack,igniter);
    void* swap_buffer = malloc(elw);
    while (task_stack.len){
        quick_sort_get_task_and_continue(base, elw, less, guest_less, swap_buffer, &task_stack);
    }
    free(swap_buffer);
    VEC_delete(&task_stack);
}
// }}} quick_sort

#define LESSIFY(lf) (bool(*)(void*, void*, void*))(lf)

bool LESS(int64_t *a, int64_t *b, void* _u){
    return *a < *b;
}

int main(){
    srand(time(NULL));
    size_t n;
    scanf("%lu", &n);
    int64_t* arr = calloc(n, sizeof(int64_t));
    for (int i = 0; i < n; i++){
        scanf("%ld", &arr[i]);
    }
    quick_sort(arr, n, sizeof(int64_t), LESSIFY(LESS), NULL);
    for (int i = 0; i < n; i++){
        printf("%ld ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}