/* 1st semester, 1st module, task 11
 * Binsearch
 * binsearch
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

unsigned long binsearch(unsigned long n, int (*compare)(unsigned long i)){
    size_t l = 0;
    size_t r = n;
    while (l + 1 < r){
        size_t m = (l + r) / 2;
        *((compare(m) <= 0) ? &l : &r) = m;
    }
    if (compare(l) < 0){
        return n;
    }
    return l;
}

//const int arr[] = {1, 2, 3, 4, 50, 51, 61};
//
//int c(size_t i){
//    int s = 44;
//    if (arr[i] < s){
//        return -1;
//    } else if (arr[i] == s){
//        return 0;
//    }
//    return 1;
//}
//
//int main(){
//    printf("%lu\n", binsearch(sizeof(arr) / sizeof(arr[0]), &c));
//}