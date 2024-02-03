/* 1st semester, 2nd module, task 6
 * heapsort
 * Heap on array operations, heap sort inplace, vector of uint8_t
 * Time: O(n*log(n))
 * Memory: O(n)
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

// hsort_nl {{{
struct hsort_nl_less_org{
    bool(*less)(void*, void*, void*);
    void* guest_less;
};

bool hsort_nl_greater(void* a, void* b, void* guest_ptr){
    struct hsort_nl_less_org* guest_ptr_recog = (struct hsort_nl_less_org*)guest_ptr;
    return guest_ptr_recog->less(b, a, guest_ptr_recog->guest_less);
}

void hsort_nl(void* base, size_t n, size_t width, bool(*less)(void*, void*, void*), void* guest_less){
    struct hsort_nl_less_org yyy;
    yyy.less = less;
    yyy.guest_less = guest_less;
    build_min_heap(base, n, width, hsort_nl_greater, &yyy);
    void *swap_buf = malloc(width);
    for (size_t i = n - 1; i > 0; i--){
        swap(base, (uint8_t*)base + width * i, swap_buf, width);
        min_heap_sift_down(base, i, width, hsort_nl_greater, &yyy, 0);
    }
    free(swap_buf);
}
// }}} hsort_nl

bool aLESb(void* a, void* b, int(*compare)(void* a, void* b)){
    return compare(a, b) < 0;
}

bool aGRTb(void* a, void* b, int(*compare)(void* a, void* b)){
    return compare(a, b) > 0;
}

// hsort {{{
bool aLESb_clean(void* a, void* b, void* compare){
    return aLESb(a, b, compare);
}

void hsort(void* base, size_t n, size_t width, int(*compare)(const void* a, const void* b)){
    hsort_nl(base, n, width, aLESb_clean, compare);
}
// }}} hsort

// Here we go again
// struct VEC {{{
#define vector struct VEC
vector{
    uint8_t* data;
    size_t len;
    size_t allocated;
};

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
            // Let's just say you don't want to allocate 2^63 bytes, okay?
            new_sz <<= 1;
        }
        uint8_t *new_block = calloc(new_sz, sizeof(uint8_t));
        memcpy(new_block, this->data, this->len * sizeof(uint8_t));  // Lmao
        free(this->data);
        this->allocated = new_sz;
        this->data = new_block;
    } else {
        this->allocated = v;
        this->data = calloc(v, sizeof(uint8_t));
    }
}

// New elements are val
void VEC_ensure_len(vector* this, size_t len, size_t val){
    VEC_ensure_allocation(this, len);
    if (len > this->len){
        for (size_t i = this->len; i < len; i++){
            this->data[i] = val;
        }
        this->len = len;
    }
}

void VEC_push_back(vector* this, uint8_t v){
    VEC_ensure_len(this, this->len + 1, 0);
    this->data[this->len - 1] = v;
}
// }}} struct VEC

struct StringInfo{
    size_t id;
    int ac;
};

bool main_comp(void* _a, void* _b, void* _u){
    struct StringInfo* a = _a;
    struct StringInfo* b = _b;
    if (a->ac < b->ac){
        return true;
    }
    if (b->ac < a->ac){
        return false;
    }
    return a->id < b->id;
}

int main(){
    assert(NULL == 0);
    vector input = VEC_new();
    VEC_ensure_allocation(&input, 1000);
    unsigned int n;
    scanf("%u", &n);
    char** strings = calloc(n, sizeof(char*));
    for (int i = 0; i < n; i++){
        input.len = 0;
        VEC_ensure_len(&input, 1, 0);
        int j = 0;
        bool s = false;
        while (true){
            int ch = getc(stdin);
            if (ch == EOF){
                break;
            }
            if (ch <= 32){
                if (s){
                    break;
                } else {
                    continue;
                }
            }
            s = true;
            VEC_ensure_len(&input, j + 2, 0);
            input.data[j] = ch;
            j++;
        }
        strings[i] = malloc(j + 1);
        memcpy(strings[i], input.data, j + 1);
    }
    VEC_delete(&input);
    struct StringInfo* arr = calloc(n, sizeof(struct StringInfo));
    for (int i = 0; i < n; i++){
        arr[i].id = i;
        arr[i].ac = 0;
        char* cur = strings[i];
        while (*cur){
            if (*cur == 'a'){
                arr[i].ac++;
            }
            cur++;
        }
    }
    hsort_nl(arr, n, sizeof(struct StringInfo), main_comp, NULL);
    for (int i = 0; i < n; i++){
        printf("%s\n", strings[arr[i].id]);
    }

    for (int i = 0; i < n; i++){
        free((char*)strings[i]);
    }
    free(strings);
    free(arr);
}
