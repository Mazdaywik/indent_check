/* 1st semester, 2nd module, task 17
 * rangemax
 * primitive "max on seg + update one" segment tree
 * Time: O(n + q * log(n))
 * Memory: O(n); log(n) per request
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

// Nothing to see here
uint64_t max_lu(uint64_t a, uint64_t b){
    return (a > b) ? a : b;
}
// Scroll down
// It's just a student wasting time on useless language
int64_t max_ld(int64_t a, int64_t b){
    return (a > b) ? a : b;
}
// Nothing to see here

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

typedef struct{
    int64_t maximum;
    size_t fch;  // Turns out it's quite impossible to make pure segment tree on array
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

// Use only on non-leaf nodes or you will die in pain
void st_update(STNode* tree, size_t N){
    tree[N].maximum = max_ld(tree[tree[N].fch].maximum, tree[tree[N].fch + 1].maximum);
}

void generate_segment_tree_sub(int64_t* arr, size_t L, size_t R, STNode* tree, size_t N, size_t* AM){
//    printf("(node %lu) [%lu; %lu) allocated: %lu\n", N, L, R, *AM);
    if (L + 1 == R){
        tree[N].maximum = arr[L];
        tree[N].fch = 0;  // whatever
    } else {
        size_t split = st_get_split(L, R);
        tree[N].fch = (*AM);
//        assert(*AM < 100 && tree[N].fch < 100);
        (*AM) += 2;
        generate_segment_tree_sub(arr, L, split, tree, tree[N].fch, AM);
        generate_segment_tree_sub(arr, split, R, tree, tree[N].fch + 1, AM);
        st_update(tree, N);
    }
}

STNode* generate_segment_tree(int64_t *arr, size_t n){
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
int64_t st_get_maximum_sub(STNode* st_arr, size_t L, size_t R, size_t Nid, size_t a, size_t b){
//    printf("max on [%lu; %lu) => node %lu [%lu;%lu]\n", a, b, Nid, L, R);
    if (a <= L && R <= b){
        return st_arr[Nid].maximum;
    }
    if (b <= L || R <= a){
        return -1e18;
    }
    size_t split = st_get_split(L, R);
    size_t left_child = st_arr[Nid].fch;
    assert(left_child);
    return max_ld(st_get_maximum_sub(st_arr, L, split, left_child, a, b),
                  st_get_maximum_sub(st_arr, split, R, left_child + 1, a, b));
}

int64_t st_get_maximum(STNode* st_arr, size_t n, size_t a, size_t b){
    // 0 n 0 - segment [0; n) st vertex 0 - that is root
    return st_get_maximum_sub(st_arr, 0, n, 0, a, b);
}

void st_update_number_sub(STNode* st_arr, size_t L, size_t R, size_t Nid, size_t index, int64_t value){
    assert(L <= index && index < R);
    if (L + 1 == R){
        st_arr[Nid].maximum = value;
    } else {
        size_t split = st_get_split(L, R);
        size_t left_child = st_arr[Nid].fch;
        assert(left_child);
        if (index < split){
            st_update_number_sub(st_arr, L, split, left_child, index, value);
        } else {
            st_update_number_sub(st_arr, split, R, left_child + 1, index, value);
        }
        st_update(st_arr, Nid);
    }
}

void st_update_number(STNode* st_arr, size_t n, size_t index, int64_t value){
    st_update_number_sub(st_arr, 0, n, 0, index, value);
}

int main(){
    uint64_t n;
    scanf("%lu", &n);
    int64_t* arr = calloc(n, sizeof(int64_t));
    for (size_t i = 0; i < n; i++){
        scanf("%ld", &arr[i]);
    }
    STNode* ST = generate_segment_tree(arr, n);
    free(arr);
    char buf[4];
    while (true){
        weird_input(buf, 4);
//        printf("%s\n", buf);
        if (buf[0] == 'M'){
            // MAX
            uint64_t l, r;
            scanf("%lu %lu", &l, &r);
            assert(l <= r && r < n);
            int64_t res = st_get_maximum(ST, n, l, r + 1);
            printf("%ld\n", res);
        } else if (buf[0] == 'U'){
            // UPD
            uint64_t index;
            int64_t value;
            scanf("%lu %ld", &index, &value);
            assert(index < n);
            st_update_number(ST, n, index, value);
        } else if (buf[0] == 'E'){
            break;
        } else {
            assert(false);
        }
    }
    free(ST);
    return 0;
}