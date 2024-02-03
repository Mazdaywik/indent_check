#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int KMPSubst(char *s, char *t){
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
        if(q == 0){
            free(p);
            return 0;
        }
        k += 1;
    }
    free(p);
    return 1;
}

int main(int args, char **argv){
    char *s = argv[1];
    char *t = argv[2];
    int len_t = strlen(t);
    int len_s = strlen(s);
    
    int is_s_of_prefix = KMPSubst(s, t);
    if(is_s_of_prefix == 0){
        printf("no");
    }
    else{
        printf("yes");
    }
    
    return 0;
}
