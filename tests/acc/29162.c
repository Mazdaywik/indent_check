/* 1st semester, 1st module, task 5
 * Permut
 * Generation of next permutation (in some convoluted order)
 * "I fixed issue with sorting. Now nothing is being sorted"
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

void swap_u32(uint32_t* a, uint32_t* b){
    uint32_t t = *a;
    *a = *b;
    *b = t;
}

void reverse_u32_seq(uint32_t* beg, int S){
    if (S == 0){ return;}
    int L = 0;
    int R = S - 1;
    while (L < R){
        swap_u32(beg + L, beg + R);
        L++;
        R--;
    }
}

// From max to min if looking at perm in reverse
// 0 1 2 3
// 1 0 2 3
// 0 2 1 3
// 2 0 1 3
// 1 2 0 3
// 2 1 0 3
// 0 1 3 2
// ...
// 2 3 1 0
// 3 2 1 0
bool next_iteration(uint32_t* perm, int n){
    int R = 1;
    while (R < n && perm[R - 1] > perm[R]){
        R++;
    }
    if (R < n){
        for (int i = 0; i < R; i++){
            if (perm[i] < perm[R]){
                swap_u32(perm + i, perm + R);
                break;
            }
        }
    }
    reverse_u32_seq(perm, R);
    return R < n;
}

int main(){
    const int n = 8;
    int64_t A[n];
    int64_t B[n];
    for (int i = 0; i < n; i++){
        scanf("%ld", &(A[i]));
    }
    for (int i = 0; i < n; i++){
        scanf("%ld", &(B[i]));
    }
    bool found = false;
    uint32_t perm[n];
    for (int i = 0; i < n; i++){
        perm[i] = i;
    }
//    int searched = 0;
    while (true){
//        for (int i = 0; i < n; i++){
//            printf("%u ", perm[i]);
//        }
//        printf("\n");
        bool have_mismatch = false;
        for (int i = 0; i < n; i++){
            if (A[perm[i]] != B[i]){
                have_mismatch = true;
                break;
            }
        }
        if (!have_mismatch){
            found = true;
            break;
        }
//        searched++;
        bool no_loopback = next_iteration(perm, n);
        if (!no_loopback){
//            int f = 1;
//            for (int i = 1; i <= n; i++){
//                f *= i;
//            }
//            assert(f == searched);
            break;
        }
    }
    printf("%s\n", found ? "yes" : "no");
}
