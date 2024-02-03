/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    size_t first;
    size_t second;
} fract;

fract maxprod(int len, int *s1, int *s2){
    double maxp = 0;
    double p = 1;
    int l = 0;
    int r = 0;
    int st = 0;
    for (int i = 0; i < len; i++){
        p = p * s1[i];
        p = p / s2[i];
        if (p > maxp){
            maxp = p;
            l = st;
            r = i;
            
        }
        //printf("%d %d %f %f",i, r, maxp, p);
        if (p < 1){
            st = i + 1;
            p = 1;
        }
    }
    return (fract){l, r};
}


int main() {
    size_t n;
    scanf("%zu", &n);
    int *s1, *s2;
    s1 = (int*)malloc(n*sizeof(int));
    s2 = (int*)malloc(n*sizeof(int));
    for (size_t i = 0; i < n; ++i) {
        char slesh;
        scanf("%d%1c%d", &s1[i], &slesh, &s2[i]);
    }
    fract res = maxprod(n, s1, s2);
    printf("%zu %zu\n", res.first, res.second);
    free(s1);
    free(s2);
    return 0;
}