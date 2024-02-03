#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int* prefix(char *s, int l){
    int *pi;
    pi = (int*)malloc(l * sizeof(int));
    int t = 0;
    pi[0] = 0;
    int i = 1;
    while (i < l){
        while (t > 0 && s[t] != s[i]){
            t = pi[t - 1];
        }
        if (s[t] == s[i]) t++;
        pi[i] = t;
        i++;
    }
    return pi;
}

void KMPSubst(char *s, char *t, int *res, int ls, int lt, int lres){
    int *pi = prefix(s, ls);
    //for (int i = 0; i < ls; i++){
    //        printf("%d ", pi[i]);
    //}
    int ind = 0;
    int q = 0;
    int k = 0;
    while (k < lt){
        while (q > 0 && s[q] != t[k]){
            q = pi[q - 1];
        }
        if (s[q] == t[k]){
            q = q + 1;
        }
        if (q == ls){
            res[ind] = k - ls + 1;
            ind ++;
            q = 0;
            k = k - ls + 1;
        }
        k++;
    }
    free(pi);
}


int main(int argc, char** argv){
    if (argc != 3){
        return 0;
    }
    char *s1;
    char *t1;
    int *res;
    s1 = argv[1];
    t1 = argv[2];
    int ls1,lt1,lres;
    ls1 = (int)strlen(s1);
    lt1 = (int)strlen(t1);
    lres = lt1;
    res = (int*)malloc(lres * sizeof(int));
    for (int i = 0; i < lres; i++){
        res[i] = -1;
    }
    KMPSubst(s1,t1,res, ls1,lt1,lres);
    //res = prefix(s1, ls1);
    for (int i = 0; i < lres; i++){
        if (res[i] != -1) printf("%d ", res[i]);
    }
    printf("\n");
    free(res);
    return 0;
}