/* 1st semester, 1st module, task 12
 * Peak
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>


unsigned long peak(unsigned long n, int (*less)(unsigned long i, unsigned long j)){
    if (n == 1){
        return 0;
    }
    if (!less(0, 1)){
        return 0;
    }
    if (!less(n - 1, n - 2)){
        return n - 1;
    }
    for (size_t i = 1; i + 1 < n; i++){
        if (!less(i, i + 1) && !less(i, i - 1)){
            return i;
        }
    }
    return 0;
}
