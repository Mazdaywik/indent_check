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
    if (argc != 2){
        return 0;
    }
    char *s1;
    s1 = argv[1];
    int ls1;
    ls1 = (int)strlen(s1);
    int *pi = prefix(s1, ls1);
    int per = 1;
    
    while (per <= sqrt(ls1)) {
        int i = per * 2 - 1;
        int k = 2;
        int flag = 0;
        while (i < ls1 && pi[i] >= per) {
            printf("%d %d\n", i + 1, k);
            i += per;
            k++;
            flag = 1;
        }
        if (flag) {
            per = i;
        }
        per++;
    }
    free(pi);
    return 0;
}