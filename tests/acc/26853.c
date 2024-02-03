/* 1st semester, 2nd module, task 19
 * rangepeak
 * */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

uint64_t max_lu(uint64_t a, uint64_t b){
    return (a > b) ? a : b;
}

int64_t max_ld(int64_t a, int64_t b){
    return (a > b) ? a : b;
}

bool weird_input(char* word, int m){
    int g = 0;
    bool sw = false;
    while (true){
        int ch = getc(stdin);
        if (ch == EOF){
            word[g] = 0;
            return false;
        } else if (ch <= 32){
            if (sw){
                word[g] = 0;
                break;
            }
        } else if (g + 1 < m){
            sw = true;
            word[g] = ch;
            g++;
        } else {
            fprintf(stderr, "Input error\n");
            word[g] = 0;
            return false;
        }
    }
    return true;
}

typedef uint32_t STValue;

typedef struct{
    STValue sum;
    size_t fch;
} STNode;

// Gonna be used for a left child
// Right child is not greater than left
size_t split_segment(size_t n){
    return (n >> 1) + (n & 1);
}

size_t st_get_split(size_t L, size_t R){
    return L + split_segment(R - L);
}

size_t rec_get_seg_tree_arr_sz(size_t n){
    return (n > 1) ? (1 + rec_get_seg_tree_arr_sz(n >> 1) + rec_get_seg_tree_arr_sz((n >> 1) + (n & 1))) : 1;
}

STValue st_combine_values(STValue A, STValue B){
    return A + B;
}

void st_update(STNode* tree, size_t N){
    assert(tree[N].fch);  // No longer need to die in pain if you called it from leaf node
    tree[N].sum = st_combine_values(tree[tree[N].fch].sum, tree[tree[N].fch + 1].sum);
}

// arr is unused in this task
void generate_segment_tree_sub(bool* arr, size_t L, size_t R, STNode* tree, size_t N, size_t* AM){
    if (L + 1 == R){
        tree[N].sum = (STValue)arr[L];
        tree[N].fch = 0;  // whatever
    } else {
        size_t split = st_get_split(L, R);
        tree[N].fch = (*AM);
        (*AM) += 2;
        generate_segment_tree_sub(arr, L, split, tree, tree[N].fch, AM);
        generate_segment_tree_sub(arr, split, R, tree, tree[N].fch + 1, AM);
        st_update(tree, N);
    }
}

STNode* generate_segment_tree(bool* arr, size_t n){
    assert(n);
    size_t m = rec_get_seg_tree_arr_sz(n);
    STNode* st = calloc(m, sizeof(STNode));
    size_t AM = 1;
    generate_segment_tree_sub(arr, 0, n, st, 0, &AM);
    assert(AM == m);
    return st;
}

// a and b define a request [a; b)
// L and R are positions in original array
// Nid in id of this segment tree node
STValue st_get_sum_on_seg_SUB(STNode* st_arr, size_t L, size_t R, size_t Nid, size_t a, size_t b){
    if (a <= L && R <= b){
        return st_arr[Nid].sum;
    }
    if (b <= L || R <= a){
        return 0;  // Neutral element
    }
    size_t split = st_get_split(L, R);
    size_t left_child = st_arr[Nid].fch;
    assert(left_child);
    return st_combine_values(st_get_sum_on_seg_SUB(st_arr, L, split, left_child, a, b),
                             st_get_sum_on_seg_SUB(st_arr, split, R, left_child + 1, a, b));
}

STValue st_get_sum_on_segment(STNode* st_arr, size_t n, size_t a, size_t b){
    return st_get_sum_on_seg_SUB(st_arr, 0, n, 0, a, b);
}

void st_update_number_SUB(STNode* st_arr, size_t L, size_t R, size_t Nid, size_t index, int64_t value){
    assert(L <= index && index < R);
    if (L + 1 == R){
        st_arr[Nid].sum = value;
    } else {
        size_t split = st_get_split(L, R);
        size_t left_child = st_arr[Nid].fch;
        assert(left_child);
        if (index < split){
            st_update_number_SUB(st_arr, L, split, left_child, index, value);
        } else {
            st_update_number_SUB(st_arr, split, R, left_child + 1, index, value);
        }
        st_update(st_arr, Nid);
    }
}

void st_update_number(STNode* st_arr, size_t n, size_t index, int64_t value){
    st_update_number_SUB(st_arr, 0, n, 0, index, value);
}

bool is_peak(int32_t* arr, size_t n, size_t i){
    assert(i < n);
    if (n == 1){
        return true;
    }
    if (i == 0){
        return arr[0] >= arr[1];
    }
    if (i == n - 1){
        return arr[n - 2] <= arr[n - 1];
    }
    return arr[i - 1] <= arr[i] && arr[i] >= arr[i + 1];
}

int main(){
    size_t n;
    scanf("%lu", &n);
    // arr[i] in [-1e9; +1e9]
    int32_t* arr = calloc(n, sizeof(int32_t));
    for (int i = 0; i < n; i++){
        scanf("%d", arr + i);
    }
    bool* peak_arr = calloc(n, sizeof(bool));
    for (int i = 0; i < n; i++){
        peak_arr[i] = is_peak(arr, n, i);
    }
    STNode* ST = generate_segment_tree(peak_arr, n);
    free(peak_arr);
    char* arg_str = calloc(5, 1);
    while (true){
        weird_input(arg_str, 5);
        if (strcmp(arg_str, "PEAK") == 0){
            // #PEAK
            size_t l, r;
            scanf("%lu %lu", &l, &r);
            assert(l <= r && r < n);
            r++;
            uint32_t peaks = 0;
//            size_t S = r - l;
//            if (S == 1){
//                peaks = 1;
//            } else {
//                if (arr[l] >= arr[l + 1]){
//                    peaks++;
//                }
//                if (arr[r - 2] <= arr[r - 1]){
//                    peaks++;
//                }
//                l++;
//                r--;
//                if (l < r){
//                    peaks += st_get_sum_on_segment(ST, n, l, r);
//                }
//            }
            peaks = st_get_sum_on_segment(ST, n, l, r);
            printf("%u\n", peaks);
        } else if (strcmp(arg_str, "UPD") == 0){
            // UPD!
            size_t i;
            int32_t v;
            scanf("%lu %d", &i, &v);
            arr[i] = v;
            st_update_number(ST, n, i, is_peak(arr, n, i));
            if (i > 0){
                st_update_number(ST, n, i - 1, is_peak(arr, n, i - 1));
            }
            if (i + 1 < n){
                st_update_number(ST, n, i + 1, is_peak(arr, n, i + 1));
            }
        } else if (strcmp(arg_str, "END") == 0){
            break;
        } else {
            assert(false);
        }
    }
    free(ST);
    free(arg_str);
    free(arr);
    return 0;
}