/* 1st semester, 1st module, task 10
 * Maxarray
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

int maxarray(void *base, size_t n, size_t width, int(*compare)(void* a, void *b)){
    int res = -1;
    void* bp = NULL;
    for (int i = 0; i < n; i++){
        if (!bp || compare(base, bp) > 0){
            res = i;
            bp = base;
        }
        base = (uint8_t*)base + width;
    }
    return res;
}

// compare(a, b) =
// neg if a < b
// zero if a = b
// pos if a > b
//int int_comp(void *pa, void *pb){
//    int a = *(int*)pa;
//    int b = *(int*)pb;
//    if (a > b){
//        return 1;
//    } else if (a == b){
//        return 0;
//    }
//    return -1;
//}
//
//int main(){
//    int arr[] = {1, 2, 3, 40, 5, 6, 7};
//    printf("%d\n", maxarray(&arr[0], sizeof(arr) / sizeof(arr[0]), sizeof(int), &int_comp));
//}