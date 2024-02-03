#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))
const int maxsz = (int)1e6 + 1000;
const int inf = (int)1e9;

int main(){
    int n, l = 0, r = 0, start = -1;
    double res, su = 0, minsum = 0;
    scanf("%d", &n);
    double* a = (double*) malloc(n * sizeof(double));
    for(int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d/%d", &x, &y);
        if (x == 0) {
            a[i] = -inf;
        } else {
            a[i] = log(x) - log(y);
        }
    }
    res = a[0];
    for (int i = 0; i < n; ++i) {
        su += a[i];
        double cur = su - minsum;
        if (cur > res) {
            res = cur;
            l = start + 1;
            r = i;
        }
        if (su < minsum) {
            minsum = su;
            start = i;
        }
    }
    printf("%d %d", l, r);
    free(a);
    return 0;
}