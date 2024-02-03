/* 1st semester, 1st module, task 7
 * Saddlepoint
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

#define MD 10

int main(){
    int w, h;
    scanf("%d %d", &h, &w);
    assert(w <= MD && h <= MD);
    int64_t mat[MD][MD];
    short col_with_max[MD];
    for (short y = 0; y < h; y++){
        int64_t max_value = -1e18;
        short ind = -1;  // col_with_max[y]
        for (short x = 0; x < w; x++){
            int64_t v;  // mat[x][y]
            scanf("%ld", &v);
            if (max_value < v){
                ind = x;
                max_value = v;
            } else if (max_value == v){
                ind = -1;
            }
            mat[x][y] = v;
        }
        col_with_max[y] = ind;
    }
//    for (int y = 0; y < h; y++){
//        for (int x = 0; x < w; x++){
//            printf("%ld ", mat[x][y]);
//        }
//        printf("%hd\n", col_with_max[y]);
//    }
    short ax = -1, ay = -1;
    for (short x = 0; x < w; x++){
        int64_t min_value = 1e18;
        short ind = -1;
        for (short y = 0; y < h; y++){
            int64_t v = mat[x][y];
            if (min_value > v){
                ind = y;
                min_value = v;
            } else if (min_value == v){
                ind = -1;
            }
        }
        if (ind >= 0 && col_with_max[ind] == x){
            ax = x;
            ay = ind;
        }
    }
    if (ax < 0){
        printf("none\n");
    } else {
        printf("%hd %hd\n", ay, ax);
    }
    return 0;
}
