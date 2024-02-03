/* 1st semester, 2nd module, task 2
 * Power2
 * Integer input algorithm, Divide and rule algorithm, Bin search algorithm, Merge-sort algorithm, neighbour mask iteration 
 * Time: O(2^(n/2)*log(n*A)*n)
 * Memory: O(e + 2^(n/2))
 * Misery: O(BusyBeaver(n*999))
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <assert.h>
#include <stdint.h>

// Sweet C++, I miss you so much((
int64_t read_int(FILE* F, bool* eof){
    int64_t res = 0;
    bool neg = false;
    bool seen_i = false;
    while (true){
        int ch = fgetc(F);
        if (ch == EOF){
            (*eof) = true;
            break;
        } else if (ch == '-'){
            neg = true;
        } else if ('0' <= ch && ch <= '9'){
            seen_i = true;
            res = res * 10 + (ch - '0');
        } else {
            if (seen_i){
                break;
            }
        }
    }
    return neg ? -res : res;
}

// I HATE PURE C!!!  I HATE PURE C!!!  I HATE PURE C!!!  I HATE PURE C!!!  I HATE PURE C!!!  I HATE PURE C!!!
// also I hate the antichrist but what is more relevant is
// I HATE PURE C!!!  I HATE PURE C!!!  I HATE PURE C!!!  I HATE PURE C!!!  I HATE PURE C!!!  I HATE PURE C!!!
struct int_buffer{
    int* d;
    size_t len;
};

struct int_buffer alloc_int_buffer(size_t sz){
    assert(sz);
    struct int_buffer res;
    res.len = sz;
    res.d = malloc(sz * sizeof(int));
    assert(res.d);
    return res;
}

struct int_buffer sub_int_buffer_s(struct int_buffer arr, size_t s){
    assert(s < arr.len);
    struct int_buffer res;
    res.d = arr.d + s;
    res.len = arr.len - s;
    return res;
}

struct int_buffer sub_int_buffer_e(struct int_buffer arr, size_t e){
    assert(0 < e && e <= arr.len);
    struct int_buffer res = arr;
    res.len = e;
    return res;
}

// debug
void putout_intbuf(struct int_buffer arr){
    printf("[");
    for (size_t i = 0; i + 1 < arr.len; i++){
        printf("%d,", arr.d[i]);
    }
    printf("%d]\n", arr.d[arr.len - 1]);
}

// For merge sort
// 17:53 I just realized, that it is a terrible implementation, but I {vile curses omitted}
void run_merge(struct int_buffer gen_buf, size_t B1, size_t B2, size_t SZ2, struct int_buffer aux_buf){
    assert(B2 + SZ2 <= gen_buf.len);
    assert(B1 < B2);
    size_t SZ1 = B2 - B1;
    assert(SZ1 + SZ2 <= aux_buf.len);
    size_t p1 = 0;
    size_t p2 = 0;
    while (true){
        if (p1 == SZ1){
            memcpy(aux_buf.d + p1 + p2, gen_buf.d + B2 + p2, (SZ2 - p2) * sizeof(int));
            break;
//            while (p2 < SZ2){
//                aux_buf[p1 + p2] = gen_buf[B2 + p2];
//                p2++;
//            }
        } else if (p2 == SZ2){
            memcpy(aux_buf.d + p1 + p2, gen_buf.d + B1 + p1, (SZ1 - p1) * sizeof(int));
            break;
//            while (p1 < SZ1){
//                aux_buf[p1 + p2] = gen_buf[B1 + p1];
//                p1++;
//            }
        } else if (gen_buf.d[B1 + p1] <= gen_buf.d[B2 + p2]) {
            aux_buf.d[p1 + p2] = gen_buf.d[B1 + p1];
            p1++;
        } else {
            aux_buf.d[p1 + p2] = gen_buf.d[B2 + p2];
            p2++;
        }
    }
    memcpy(gen_buf.d + B1, aux_buf.d, (SZ1 + SZ2) * sizeof(int));
}

// I did a little bit of recursion
// You know, committed a small amount of tomfoolery
void _sub_merge_sort(struct int_buffer array, size_t Beg, size_t Size, struct int_buffer aux_buffer){
    assert(Beg + Size <= array.len);
    if (Size <= 1){
        return;
    }
    size_t SZ1 = Size / 2;
    size_t B2 = Beg + SZ1;
    size_t SZ2 = Size - SZ1;
    _sub_merge_sort(array, Beg, SZ1, aux_buffer);
    _sub_merge_sort(array, B2, SZ2, aux_buffer);
    run_merge(array, Beg, B2, SZ2, aux_buffer);
}

void merge_sort(struct int_buffer vector, struct int_buffer aux_buffer){
    _sub_merge_sort(vector, 0, vector.len, aux_buffer);
}

// I haven't even noticed as I typed new as a variable name,
// that is what C does to a man ... :(
void _sub_mask_generate_sum_array(unsigned int* mask, int* new, int* old, short lev, int* inp_data, size_t* i){
    (*new) = (*old) + (((*mask) & (1u << lev)) ? (-inp_data[lev]) : inp_data[lev]);
    (*mask) ^= (1u << lev);
    (*i)++;
}

// C99 compatible, time complexity O(2^n)
struct int_buffer generate_sum_array(struct int_buffer inp){
    short n = inp.len;
    assert(n <= 12);
    struct int_buffer res = alloc_int_buffer(1u << n);
    unsigned int mask = 0;
    res.d[0] = 0;
//    for (size_t i = 1; i < (1u << n); i++){
//        int b = ffs(i) - 1;  // PLEASE BE COMPATIBLE WITH TESTING SERVER PLEASE BE COMPATIBLE WITH TESTING SERVER 
//        // it was not compatible with testing server....
//        res.d[i] = res.d[i - 1] + ((mask & (1u << b)) ? (-inp.d[b]) : inp.d[b]);
//        mask ^= (1u << b);
//    }
    short lev = n - 1;
    size_t i = 1;
    unsigned int stack_mask = 0;
    while (lev < n){
        if (lev){
            if (stack_mask & (1u << lev)){
                // Stage 3
                stack_mask ^= (1u << lev);  // From 1 to 0
                lev++;
            } else if (mask & (1u << lev - 1)) {
                // Stage 2
                _sub_mask_generate_sum_array(&mask, &(res.d[i]), &(res.d[i - 1]), lev, inp.d, &i);
                stack_mask ^= (1u << lev);  // From 0 to 1
                lev--;
            } else {
                // Stage 1
                lev--;
            }
        } else {
            _sub_mask_generate_sum_array(&mask, &(res.d[i]), &(res.d[i - 1]), lev, inp.d, &i);
            lev++;
        }
    }
    assert (i == res.len);
    return res;
}

struct int_buffer sorted_sum_array(struct int_buffer inp, struct int_buffer aux_merger){
    struct int_buffer res = generate_sum_array(inp);
    merge_sort(res, aux_merger);
    return res;
}

struct int_buffer count_int_buf(struct int_buffer arr){
    struct int_buffer res = alloc_int_buffer(arr.len);
    res.d[0] = 1;
    // I don't want to be this weird edgy size_t kid, so I stopped doing that thing
    for (int i = 1; i < arr.len; i++){
        if (arr.d[i] == arr.d[i - 1]){
            res.d[i] = res.d[i - 1] + 1;
        } else {
            res.d[i] = 1;
        }
    }
    return res;
}

int bin_find_in_int_buf(struct int_buffer sb, int val){
    // Just kidding. I will never stop. I love unnecessarily overcomplicated type system
    size_t l = 0; // arr[l] <= val
    size_t r = sb.len;  // arr[len] > val or undefined
    while (l + 1 < r){
        size_t m = (l + r) / 2;
        if (m == sb.len || sb.d[m] > val){
            r = m;
        } else {
            l = m;
        }
    }

    return sb.d[l] == val ? l : -1;
}

int main(){
    const int MAX_N = 24;
    const short MAX_P = 25;  // Maybe it is 24, i forgor, anyway, doesn't matter
#ifdef LOC
    FILE* F = fopen("input.txt", "r");
#else
    FILE* F = stdin;
#endif    
    bool sus = false;
    int n = read_int(F, &sus);
    assert(0 < n && n <= MAX_N);
    struct int_buffer iab = alloc_int_buffer(n);
    for (int i = 0; i < n; i++){
        iab.d[i] = read_int(F, &sus);
    }
    if (n == 1){
        int f = 0;
        for (int i = 0; i <= MAX_P; i++){
            if (iab.d[0] == (1u << i)){
                f = 1;
                break;
            }
        }
        printf("%d\n", f);
//        if (a[0] && (a[0] == (1u << (ffs(a[0]) - 1))))
    } else {
        int m = n / 2;
        struct int_buffer aux_merge_buffer = alloc_int_buffer(1u << (n / 2 + 1));
        struct int_buffer A1 = generate_sum_array(sub_int_buffer_e(iab, m));  // Changed End to m (exclusive)
        struct int_buffer A2 = sorted_sum_array(sub_int_buffer_s(iab, m), aux_merge_buffer);  // Changed Start to m
        struct int_buffer A2_cnt = count_int_buf(A2);
        unsigned long answer = 0;
        for (size_t i = 0; i < A1.len; i++){
            int v = A1.d[i];
            for (int p = 0; p <= MAX_P; p++){
                int req = (1u << p) - v;
                int l = bin_find_in_int_buf(A2, req);
                if (l >= 0){
                    answer += A2_cnt.d[l];
                }
            }
        }
        printf("%lu\n", answer);
        free(A2_cnt.d);
        free(A1.d);
        free(A2.d);
        free(aux_merge_buffer.d);
    }
    free(iab.d);
#ifdef LOC
    fclose(F);
#endif
    return 0;
}
