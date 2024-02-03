#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b

struct root{
    struct root *parent;
    long value;
    struct root *left;
    struct root *right;
    int start;
    int end;
};

int per(struct root *rootEl, int i, int j){
    return (rootEl->start<=i && rootEl->end >= i) || (rootEl->start<=j && rootEl->end >= j) || (i<=rootEl->start && j >= rootEl->end);
}

long maxEl(struct root *rootEl, int i, int j){
    if((rootEl->left == NULL && rootEl->right == NULL) || (i<=rootEl->start && j >= rootEl->end))
        return rootEl->value;
    if(rootEl->right == NULL) {
        return maxEl(rootEl->left, i, j);
    }
    int f1 = per(rootEl->left, i, j);
    int f2 = per(rootEl->right, i, j);
    if(f1 && f2)
        return max(maxEl(rootEl->left, i, j), maxEl(rootEl->right, i, j));
    if(f1)
        return maxEl(rootEl->left, i, j);
    if(f2)
        return maxEl(rootEl->right, i, j);
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    struct root *roots = calloc(n*4, sizeof(struct root));
    for(int i = 0 ; i < n ; i++) {
        scanf("%ld", &roots[i].value);
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
            roots[end++].value = max(roots[i].value, roots[i + 1].value);
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
    char command[5];
    scanf("%s", command);
    while (command[0] != 'E'){

        if(command[0] == 'M'){
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%ld\n", maxEl(&roots[end], l, r));
        }
        if(command[0] == 'U'){
            int j, v;
            scanf("%d%d", &j, &v);
            struct root *now = &roots[j];
            roots[j].value = v;
            now = now->parent;
            while (now != NULL){
                if(now->right == NULL){
                    now->value = now->left->value;
                    now = now->parent;
                    continue;
                }
                now->value = max(now->left->value, now->right->value);
                now = now->parent;
            }
        }

        scanf("%s", command);
    }
    free(roots);
    return 0;
}
