#include <stdio.h>
#include <stdlib.h>

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

long peakEl(struct root *rootEl, int i, int j){
    if((rootEl->left == NULL && rootEl->right == NULL) 
       ||  (i<=rootEl->start && j >= rootEl->end))
        return rootEl->value;
    if(rootEl->right == NULL) {
        return peakEl(rootEl->left, i, j);
    }
    int f1 = per(rootEl->left, i, j);
    int f2 = per(rootEl->right, i, j);
    if(f1 && f2)
        return peakEl(rootEl->left, i, j) + peakEl(rootEl->right, i, j);
    if(f1)
        return peakEl(rootEl->left, i, j);
    if(f2)
        return peakEl(rootEl->right, i, j);
}

void UPD(struct root *now){
    now = now->parent;
    while (now != NULL){
        if(now->right == NULL){
            now->value = now->left->value;
            now = now->parent;
            continue;
        }
        now->value = now->left->value + now->right->value;
        now = now->parent;
    }
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    struct root *roots = calloc(n*4, sizeof(struct root));
    long *array = calloc(n + 1, sizeof(long));
    for(int i = 0 ; i < n ; i++) {
        scanf("%ld", &array[i]);
        roots[i].left = NULL;
        roots[i].right = NULL;
        roots[i].start = i;
        roots[i].end = i;
    }
    for(int i = 1 ; i < n - 1 ; i++){
        roots[i].value = (array[i]>=array[i-1])&&(array[i]>=array[i+1]);
    }
    if(n!=1)
        roots[0].value = (array[0]>=array[1]);
    else{
        roots[0].value = 1;
    }
    if(n!=1)
        roots[n-1].value = (array[n-1]>=array[n-2]);
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
            roots[end++].value = roots[i].value + roots[i + 1].value;
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
        if(command[0] == 'P'){
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%ld\n", peakEl(&roots[end], l, r));
        }
        if(command[0] == 'U'){
            int j, v;
            scanf("%d%d", &j, &v);
            array[j] = v;
            if(j==0){
                if(n!=1) {
                    roots[j].value = v >= array[j + 1];
                    if( n != 2)
                        roots[j + 1].value = ((array[j + 1] >= array[j + 2]) 
                                              && (array[j + 1] >= v));
                    else
                        roots[j + 1].value = (array[j + 1] >= v);
                    UPD(&roots[j+1]);
                    UPD(&roots[j]);
                }
            }else{
                if(j == n-1){
                    if(n!=1) {
                        roots[j].value = v >= array[j - 1];
                        if(n != 2)
                            roots[j - 1].value = ((array[j - 1] >= array[j - 2]) 
                                                  && (array[j - 1] >= v));
                        else
                            roots[j - 1].value = (v <= array[j - 1]);
                        UPD(&roots[j-1]);
                        UPD(&roots[j]);
                    }
                }else{
                    roots[j].value = (v >= array[j - 1]) && (v >= array[j + 1]);
                    if(n != 2 && j != 1)
                        roots[j - 1].value = ((array[j - 1] >= array[j - 2]) 
                                              && (array[j - 1] >= v));
                    else
                        roots[j - 1].value = (v <= array[j - 1]);
                    if(n != 2 && j != n-2)
                        roots[j + 1].value = ((array[j + 1] >= array[j + 2]) 
                                              && (array[j + 1] >= v));
                    else
                        roots[j + 1].value = (array[j + 1] >= v);
                    UPD(&roots[j+1]);
                    UPD(&roots[j-1]);
                    UPD(&roots[j]);
                }
            }
        }
        scanf("%s", command);
    }
    free(roots);
    free(array);
    return 0;
}