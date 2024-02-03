#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int PrefixFunction(char *s, char *T){
    int s_len = strlen(s);
    int t_len = strlen(T);
    int prefix[s_len];

    int q = 0;
    prefix[0] = 0;
    for(int i = 1; i < s_len; i++){
        while(q > 0 && s[q] != s[i]){
            q = prefix[q-1];
        }

        if(s[q] == s[i]) 
            q++;
        prefix[i] = q;
    }


    q = 0;
    for(int i = 0; i < t_len; i++){
        while(q > 0 && s[q] != T[i])
            q = prefix[q-1];

        if(s[q] == T[i]) 
            q++;

        if(q == 0) 
            return 0;

        if(q == strlen(s))
            q = prefix[q-1];
    }
    return 1;
}

int main(int argc,char **argv){
    char *S = argv[1];
    char *T = argv[2];

    if(PrefixFunction(S, T)) 
        printf("yes\n");
    else 
        printf("no\n");
    return 0;
}