#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* pref(char *s, int s_len) {
    int k = 0;
    int* pi = malloc(s_len * sizeof(int));
    pi[0] = 0;

    for (int i = 1; i < s_len; i++) {
        while (k > 0 && s[k] != s[i])
            k = pi[k - 1];
        if (s[k] == s[i])
            k++;
        pi[i] = k;
    }
    return pi;
}

int main(int argc, char** argv) {
    
    

    char* S = argv[1];
    char* T = argv[2];
   
    int S_len = strlen(S);
    int T_len = strlen(T);

    char* mega_string =(char*) malloc( (S_len + T_len + 1) * sizeof(char) );
    strcpy(mega_string, S);
    strcat(mega_string, T);
    int *pi = pref(mega_string, S_len + T_len);
    for (int i = S_len; i < S_len + T_len; i++){
        if(pi[i] == 0){
            printf("no\n");
            free(pi);
            free(mega_string);
            return 0;
        }
    }

    printf("yes\n");
    free(pi);
    free(mega_string);
    return 0;
}