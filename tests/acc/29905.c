#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

//int cnt(int* a, int n, int obj){
//    int counter = 0;
//    for (int i = 0; i < n; ++i){
//        if (obj & (1 << i)){
//            counter += a[i];
//        }
//    }
//    return counter;
//}

int is_pwr(int x, int n){
    int counter = 0;
    for (int i = 0; i < 25; ++i){
        if (x == (1 << i)){
            counter += 1;
        }
    }
    return counter;
}

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    int* a = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < (1 << n); ++i) {
        int su = 0;
        for (int j = 0; j < n; ++j){
            if (i & (1 << j)){
                su += a[j];
            }
        }
        for (int j = 0; j < 25; ++j){
            if (su == (1 << j)){
                ans += 1;
            }
        }
    }
    printf("%d", ans);
    free(a);
    return 0;
}