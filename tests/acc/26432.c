#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

void *Delata1(char *s, int size){
    int *d1 = calloc(size, sizeof(int));
    int a = 0;
    int len = strlen(s);
    while(a < size){
        d1[a] = len;
        a += 1;
    }
    int j = 0;
    while(j < len){
        d1[s[j]] = len - j - 1;
        j += 1;
    }
    return d1;
}


void *Suffix(char *s){
    int len = strlen(s);
    int t = len - 1;
    int *d = calloc(len, sizeof(int));
    d[t] = t;
    int i = len - 2;
    while(i >= 0){
        while(t < len - 1 && s[t] != s[i]){
            t = d[t + 1];
        }
        if(s[t] == s[i]){
                t -= 1;
            }
            d[i] = t;
        i -= 1;
    }
    return d;
}


void *Delta2(char *s){
    int len = strlen(s);
    int *d2 = calloc(len, sizeof(int));
    int *d = Suffix(s);
    int i = 0;
    int t = 0;
    t = d[0];
    while (i < len){
        while(t < i){
            t = d[t + 1];
        }
        d2[i] = -i + t + len;
        i += 1;
    }
    i = 0;
    while(i < len - 1){
        t = i;
        while(t < len - 1){
            t = d[t + 1];
            if(s[i] != s[t]){
                d2[t] = -(i + 1) + len;
            }
        }
        i += 1;
    }
    free(d);
    return d2;
}

void BMSubst(char *s, int size, char *t){
    int lens = strlen(s);
    int lent = strlen(t);
    int *d1 = Delata1(s, size);
    int *d2 = Delta2(s);
    int k = lens - 1;
    int i = 0;
    while(k < lent){
        i = lens - 1;
        while(t[k] == s[i]){
            if(i == 0){
                printf("%d ", k);
                break;
            }
            i -= 1;
            k -= 1;
        }
        k = k + MAX(d1[t[k]], d2[i]);
    }
    k = lent;
    free(d1);
    free(d2);
}


int main(int args, char **argv){
    char *s = argv[1];
    char *t = argv[2];
    BMSubst(s, 126, t);
    return 0;
}