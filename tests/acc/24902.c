#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct sizeofarr{
    void *arr;
    int size;
};


void *Prefix(char *s){
    int len = strlen(s);
    int *p = calloc(len, sizeof(int));
    p[0] = 0;
    int t = 0;
    int i = 1;
    while(i < len){
        while(t > 0 && s[t] != s[i]){
            t = p[t-1];
        }
        if(s[t] == s[i]){
            t += 1;
        }
        p[i] = t;
        i += 1;
    }
    return p;
}


void *KMPSubst(char *s, char *t){
    int *inds = (int*)malloc(sizeof(int));
    inds[0] = '\n';
    int count = 0;
    int *p = Prefix(s);
    int q = 0;
    int k = 0;
    int lenT = strlen(t);
    int lenS = strlen(s);
    while(k < lenT){
        while(q > 0 && s[q] != t[k]){
            q = p[q-1];
        }
        if(s[q] == t[k]){
            q += 1;
        }
        if(q == lenS){
            int index = k - lenS + 1;
            if(count == 0){
                inds[0] = index;
            } 
            else{
                int *tmp = (int*)malloc(count * sizeof(int));
                memcpy(tmp, inds, count * sizeof(int));
                free(inds);
                inds = (int*)malloc((count + 1) * sizeof(int));
                memcpy(inds, tmp, count * sizeof(int));
                free(tmp);
                inds[count] = index;
            }
            count += 1;
        }
        k += 1;
    }
    struct sizeofarr *res = malloc(sizeof(struct sizeofarr));
    res[0].arr = inds;
    res[0].size = count;
    free(p);
    return res;
}

int main(int args, char **argv){
    char *s = argv[1];
    char *t = argv[2];
    struct sizeofarr *res = (struct sizeofarr*)KMPSubst(s, t);
    int *inds = res[0].arr;
    int count = res[0].size;
    for(int i = 0; i < count; i++){
        printf("%i ", inds[i]);
    }
    free(inds);
    free(res);
    return 0;
}
