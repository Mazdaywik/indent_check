#include <stdio.h>
#include <math.h>

#define MAX 1000000
#define EPS 0.00001

void maxprod(int a, int b, int* l, int* r, int i){
    static int start = 0;
    static double num, max_sum = -MAX, sum = 0;
    if (b == 0)
        num = -MAX;
    else
        num = log(b) - log(a);
    if (sum < 0)
        sum = 0, start = i;
    sum += num;
    if (sum - max_sum > EPS){
        max_sum = sum;
        *l = start;
        *r = i;
        }
}

int main(){
    int n;
    scanf("%d", &n);
    int a, b, l = 0, r = 0;
    for (int i = 0; i < n; i++){
        scanf("%d/%d", &b, &a);
        maxprod(a, b, &l, &r, i);
    }
    printf("%d %d\n", l, r);
    return 0;
}