#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int* delta1(char* s, int l) {
    int sz = (126 - 33 + 1);
    int *del1;
    del1 = (int*)malloc((size_t)sz * sizeof(int));
    for (int i = 0; i < sz; ++i) {
        del1[i] = l;
    }
    for (int i = 0; i < l; ++i) {
        del1[s[i] - 33] = l - i - 1;
    }
    return del1;
}

int* suffix(char *arr, int l){
    int *q;
    q = (int*)calloc(l, sizeof(int));
    int t = l - 1;
    q[l - 1] = t;
    int i = l - 2;
    while (i >= 0){
        while (t < l - 1 && arr[t] != arr[i]){
            t = q[t + 1];
        }
        if (arr[t] == arr[i]) t--;
        q[i] = t;
        i--;
    }
    return q;
}

int* delta2(char *arr, int l){
    int *del2;
    del2 = (int*)calloc(l, sizeof(int));
    int *q = suffix(arr, l);
    int t = q[0];
    int i = 0;
    while (i < l){
        while (t < i){
            t = q[t + 1];
        }
        del2[i] = t + l - i;
        i++;
    }
    i = 0;
    while (i < l - 1){
        t = i;
        while (t < l - 1){
            t = q[t + 1];
            if (arr[i] != arr[t]) del2[t] = l - (i + 1);
        }
        i++;
    }
    free(q);
    return del2;
}

int main(int argc, char** argv){
    if (argc != 3){
        return 0;
    }
    char *s1;
    char *t1;
    s1 = argv[1];
    t1 = argv[2];
    int ls1,lt1;
    ls1 = (int)strlen(s1);
    lt1 = (int)strlen(t1);
    int *d1 = delta1(s1, ls1);
    int *d2 = delta2(s1, ls1);
    int k = ls1 - 1;
    while (k < lt1){
        int i = ls1 - 1;
        while (t1[k] == s1[i]){
            if (i == 0){
                printf("%d ", k);
                break;
            }
            i--;
            k--;
        }
        k = k + fmax(d1[t1[k] - 33], d2[i]);
    }
    printf("\n");
    free(d1);
    free(d2);
    return 0;
}