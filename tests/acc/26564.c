#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int GCD(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;        
    }
    return abs(a);
}

void *build(int *nums, int i, int a, int b, int *t){
    int m = 0;
    if(a == b){
        t[i] = nums[a];
    }
    else{
        m = (int)floor((a + b) / 2);
        build(nums, 2 * i + 1, a, m, t);
        build(nums, 2 * i + 2, m + 1, b, t);
        t[i] = GCD(t[2*i+1], t[2*i+2]);
    }
    return t;
}

int query(int *t, int l, int r, int i, int a, int b){
    int _gcd, m = 0;
    if(l == a && r == b){
        _gcd = t[i];
    }
    else{
        m = (int)floor((a + b) / 2);
        if(r <= m){
            _gcd = query(t, l, r, 2 * i + 1, a, m);
        }
        else if(l > m){
            _gcd = query(t, l, r, 2 * i + 2, m + 1, b);
        }
        else{
            _gcd = GCD(query(t, l, m, 2 * i + 1, a, m), query(t, m + 1, r, 2 * i + 2, m + 1, b));
        }
    }
    return _gcd;
}


void *SegmentTree_Build(int *nums, int size){
    int *t = calloc(size * 4, sizeof(int));
    build(nums, 0, 0, size - 1, t);
    return t;
}

int SegmentTree_Query(int *t, int n, int l, int r){
    int _gcd = query(t, l, r, 0, 0, n - 1);
    return _gcd;
}

int main(int args, char **argv){
    int n = 0;
    scanf("%d", &n);
    int *nums = calloc(n, sizeof(int));
    int i = 0;
    for(int i = 0; i < n; i++){
        int num = 0;
        scanf("%d", &num);
        nums[i] = num;
    }
    int *t = SegmentTree_Build(nums, n);
    int m = 0;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int l, r = 0;
        scanf("%d", &l);
        scanf("%d", &r);
        int _gcd = SegmentTree_Query(t, n, l, r);
        printf("%d\n", abs(_gcd));
    }
    free(t);
    free(nums);
    return 0;
}
