/* 1st semester, 2nd module, task 13
 * kmpal
 * Knuth-Morris-Pratt algorithm
 * Supports only ASCII strings
 * Each invocation of this program costs us 1 dollar
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
    assert(argc == 3);
    size_t SL = strlen(argv[1]);
    size_t TL = strlen(argv[2]);
    size_t n = SL + TL + 1;
    char* cat_str = malloc(n * 1);
    memcpy(cat_str, argv[1], SL);
    cat_str[SL] = '$';
    memcpy(&cat_str[SL + 1], argv[2], TL);
    size_t* P = prefix_function(cat_str, n);
    for (size_t i = SL - 1; i < TL; i++){
        if (P[SL + 1 + i] == SL){
            printf("%lu\n", i + 1 - SL);
        }
    }
    free(cat_str);
    free(P);
    return 0;
}