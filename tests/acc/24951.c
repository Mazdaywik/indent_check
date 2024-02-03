#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


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


void *KMPSubst(char *s, char *t, int *p, int lenT, int lenS){
    int *inds = (int*)malloc(sizeof(int));
    inds[0] = '\n';
    int count = 0;
    int q = 0;
    int k = 0;
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
    return res;
}


int main(int args, char **argv){
    char *s = argv[1];
    int *p = Prefix(s);
    int lens = strlen(s);
    for(int i = 0; i < lens; i++){
        int len_pref = i + 1;
        int count = 0;
        if(p[i] != 0){
            int mid = (int) len_pref / 2;
            char *pref_s = calloc(len_pref + 1, sizeof(char));
            strncpy(pref_s, s, len_pref);
            for(int j = 0; j < mid; j++){
                char *under_s = calloc((j + 2),sizeof(char));
                strncpy(under_s, s, j + 1);
                struct sizeofarr *res = (struct sizeofarr*)KMPSubst(under_s, pref_s, p, len_pref, j + 1);
                int *inds = res[0].arr;
                int tmp_count = res[0].size;
                bool accepted = true;
                for(int k = 0; k < tmp_count; k++){
                    for(int kk = k + 1; kk < tmp_count; kk++){
                        if(inds[kk] < inds[k] + j + 1) accepted = false;
                    }
                }
                if(tmp_count > count && tmp_count * (j + 1) == len_pref && accepted) count = tmp_count;
                free(inds);
                free(under_s);
                free(res);
            }
            if(count > 0){
                printf("%i ", len_pref);
                printf("%i\n", count);
            }
            free(pref_s);
        }
    }
    free(p);
    return 0;
}
