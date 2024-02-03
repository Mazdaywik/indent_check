/* 1st semester, 2nd module, task 12
 * prefixes
 * prefix-function, min-period size from 2nd max circumfix size
 * Supports only ASCII strings
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t byte;

// Searches for length of longest circumfix of each prefix
// Dont forget to dealloc this
size_t* prefix_function(char* str, size_t n){
    size_t* P = calloc(n, sizeof(size_t)); // P[0] = 0
    for (size_t i = 1; i < n; i++){
        size_t k = P[i - 1];
        while (str[i] != str[k] && k){
            k = P[k - 1];
        }
        P[i] = k ? k + 1 : (str[i] == str[0]);
    }
    return P;
}


int main(int argc, char** argv){
    assert(argc == 2);
    char* our_str = argv[1];
    size_t n = strlen(our_str);
    size_t* P = prefix_function(our_str, n);
//    printf("%s\n", our_str);
//    for (int i = 0; i < n; i++){
//        printf("%lu ", P[i]);
//    }
//    printf("\n");
    for (size_t i = 0; i < n; i++){
        size_t m = i + 1;
        assert(P[i] < m);
        size_t r = m - P[i];
        size_t min_p_sz = (m % r) ? m : r;
        if (min_p_sz < m){
            printf("%lu %lu\n", m, m / min_p_sz);
        }
    }
    free(P);
    return 0;
}