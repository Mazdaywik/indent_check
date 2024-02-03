#include <stdio.h>



double product(int a1, int b1, double* max_el)
{
    double el = (double) a1 / b1;
    if (el > *max_el) {
        *max_el = el;
    }
    return el;
}


void max_product(int n, int* a, int* b, int* ans_l, int* ans_r)
{
    double max_prod = 0, all = 1, max_all = 0;
    int l = 0;
    int r = 0;
    *ans_l = 0, *ans_r = 0;
    double max_el = -1;
    int is_first = 1;
    
    for (int i = 0; i < n; i++) {

        double prod = product(a[i], b[i], &max_el);
        // printf("%f %f\n", all, prod);
        if (prod * all > 1) {
            all = prod * all;
            if (is_first) {
                l = i;
                is_first = 0;
            }
            r = i;
            if (all > max_all) {
                max_all = all;
                *ans_l = l;
                *ans_r = r;
            }
        }
        else {
            all = 1;
            is_first = 1;
        }
    }
    if (max_el < 1) {
        *ans_l = max_el;
        *ans_r = max_el;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int a[n];
    int b[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d/%d", &a[i], &b[i]);
    }
    
    int l, r;
    max_product(n, a, b, &l, &r);
    
    printf("%d %d\n", l, r);
    
    return 0;
}
