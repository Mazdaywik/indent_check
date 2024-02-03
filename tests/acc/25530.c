#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int** delta1(char *s, int l) {
    int sz = (126 - 33 + 1);
    int **del1;
    del1 = (int**)malloc((size_t)l * sizeof(int*));
    for (int i = 0; i < l; i++){
        del1[i] = (int*)malloc((size_t)sz * sizeof(int));
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < sz; j++){
            del1[i][j] = l;
        }
    }
    del1[0][s[0] - 33] = l - 0 - 1;
    for (int i = 1; i < l; ++i) {
        memcpy(del1[i], del1[i - 1], (size_t)sz * (sizeof(int)));
        del1[i][s[i] - 33] = l - i - 1;
    }
    return del1;
}

int main(int argc, char** argv){
    if (argc != 3){
        return 0;
    }
    char *s1;
    char *t1;
    s1 = argv[1];
    t1 = argv[2];
    int ls1,lt1;
    ls1 = (int)strlen(s1);
    lt1 = (int)strlen(t1);
    int **d1 = delta1(s1, ls1);
    int k = ls1 - 1;
    while (k < lt1){
        int i = ls1 - 1;
        while (t1[k] == s1[i]){
            if (i == 0){
                printf("%d \n", k);
                for (int q = 0; q < ls1; q++){
                    free(d1[q]);
                }
                free(d1);
                return 0;
            }
            i--;
            k--;
        }
        k = k + fmax(d1[i][t1[k] - 33], ls1 - i);
    }
    printf("%d\n", lt1);
    for (int q = 0; q < ls1; q++){
        free(d1[q]);
    }
    free(d1);
    return 0;
}