/* 1st semester, 1st module, task 6
 * Maxk
 * */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

int64_t max(int64_t a, int64_t b){
    return (a > b) ? a : b;
}

int main(){
    int n;
    scanf("%d", &n);
    int64_t *arr = calloc(n + 1, sizeof(int64_t));
    int64_t p = 0;
    for (int i = 0; i < n; i++){
        int64_t v;
        scanf("%ld", &v);
        p += v;
        arr[i + 1] = p;
    }
    uint32_t k;
    scanf("%u", &k);
    int64_t best = -1e18;
    assert(k <= n);
    for (int i = k; i <= n; i++){
        best = max(best, arr[i] - arr[i - k]);
    }
    printf("%ld\n", best);
    free(arr);
    return 0;
}
