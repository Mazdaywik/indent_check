#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }

    return a;
}

struct root{
    struct root *parent;
    long value;
    struct root *left;
    struct root *right;
    int start;
    int end;
};

int per(struct root *rootEl, int i, int j){
    return (rootEl->start<=i && rootEl->end >= i) 
           || (rootEl->start<=j && rootEl->end >= j) 
           || (i<=rootEl->start && j >= rootEl->end);
}

long gcdEl(struct root *rootEl, int i, int j){
    if((rootEl->left == NULL && rootEl->right == NULL) 
       || (i<=rootEl->start && j >= rootEl->end))
        return rootEl->value;
    if(rootEl->right == NULL) {
        return gcdEl(rootEl->left, i, j);
    }
    int f1 = per(rootEl->left, i, j);
    int f2 = per(rootEl->right, i, j);
    if(f1 && f2)
        return gcd(gcdEl(rootEl->left, i, j), gcdEl(rootEl->right, i, j));
    if(f1)
        return gcdEl(rootEl->left, i, j);
    if(f2)
        return gcdEl(rootEl->right, i, j);
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    struct root *roots = calloc(n*4, sizeof(struct root));
    for(int i = 0 ; i < n ; i++) {
        scanf("%ld", &roots[i].value);
        roots[i].value = abs(roots[i].value);
        roots[i].left = NULL;
        roots[i].right = NULL;
        roots[i].start = i;
        roots[i].end = i;
    }
    int left = 0, end = n, right = n - 1;
    while (right > left){
        for(int i = left; i <= right; i+= 2){
            if(i == right){
                roots[end++].value = roots[i].value;
                roots[i].parent = &roots[end - 1];
                roots[end - 1].left = &roots[i];
                roots[end - 1].start = roots[i].start;
                roots[end - 1].end = roots[i].end;
                continue;
            }
            roots[end++].value = gcd(roots[i].value, roots[i + 1].value);
            roots[i].parent = &roots[end - 1];
            roots[i + 1].parent = &roots[end - 1];
            roots[end - 1].left = &roots[i];
            roots[end - 1].right = &roots[i + 1];
            roots[end - 1].start = roots[i].start;
            roots[end - 1].end = roots[i + 1].end;
        }
        left = right + 1;
        right = end - 1;
    }
    roots[--end].parent = NULL;
    int m;
    scanf("%d", &m);
    while (m--){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%ld\n", gcdEl(&roots[end], l, r));
    }
    free(roots);
    return 0;
}