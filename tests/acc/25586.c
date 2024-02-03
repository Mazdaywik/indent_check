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


int main(int argc, char** argv){
    if (argc != 3){
        return 0;
    }
    char *s1;
    char *t1;
    s1 = argv[1];
    t1 = argv[2];
    int ls1,lt1,lres;
    ls1 = (int)strlen(s1);
    lt1 = (int)strlen(t1);
    int *pi = prefix(s1, ls1);
    int q = 0;
    int k = 0;
    while (k < lt1){
        while (q > 0 && s1[q] != t1[k]){
            q = pi[q - 1];
        }
        if (s1[q] == t1[k]){
            q = q + 1;
        }
        if (q == 0){
            printf("no");
            free(pi);
            return 0;
        }
        k++;
    }
    printf("yes");
    free(pi);
    return 0;
}