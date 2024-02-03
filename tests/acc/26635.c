/* 1st semester, 2nd module, task 13
 * pword
 * Z-function
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

// O(n) time, O(1) aux memory used
size_t* Z_function(char* str, size_t n){
    size_t* Z = calloc(n, sizeof(size_t));
    size_t left = 0;
    size_t right = 0;
    for (size_t i = 1; i < n; i++){
        if (i >= right){
            size_t j = 0;
            left = i;
            while (i + j < n && str[j] == str[i + j]){
                j++;
            }
            right = i + j;
            Z[i] = j;
        } else {
            size_t s = i - left; // s > 0
            if (s + Z[s] < right - left){
                Z[i] = Z[s];
            } else {
                size_t j = right - i;
                left = i;
                while (i + j < n && str[j] == str[i + j]){
                    j++;
                }
                right = i + j;
                Z[i] = j;
            }
        }
    }
    return Z;
}

int main(int argc, char** argv){
    assert(argc == 3);
    char* S = argv[1];
    char* T = argv[2];
    size_t Sn = strlen(S);
    size_t Tn = strlen(T);
    assert(Sn && Tn);
    size_t n = Sn + 1 + Tn;
    char* crutch = calloc(n + 1, 1);
    memcpy(crutch, S, Sn);
    crutch[Sn] = '$';
    memcpy(&crutch[Sn + 1], T, Tn);
    size_t* Zed = Z_function(crutch, n);
//    printf("S: %s, T: %s, S$T: %s\n", S, T, crutch);
//    for (int i = 0; i < n; i++){
//        printf("%lu ", Zed[i]);
//    }
//    printf("\n");
    size_t reach = 0;
    for (size_t i = 0; i < Tn && i <= reach; i++){
        size_t Nv = i + Zed[Sn + 1 + i];
        if (Nv > reach){
            reach = Nv;
        }
    }
    assert(reach <= Tn);
    printf("%s\n", (reach == Tn) ? "yes" : "no");
    free(Zed);
    free(crutch);
    return 0;
}