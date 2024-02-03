#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* Prefix(char* S) {
    size_t len = strlen(S);
    int* p;
    p = (int*) calloc(len, sizeof(int));
    int t = 0, i = 1;;
    p[0] = t;
    while (i < len) {
        while (t > 0 && S[t] != S[i]) {
            t = p[t - 1];
        }
        if (S[t] == S[i]) ++t;
        p[i] = t;
        ++i;
    }
    return p;
}


int main(int argc, char** argv) {
    char* S = argv[1];
    char* T = argv[2];

    size_t len_S = strlen(S);
    size_t len_T = strlen(T);
    int* prefixes = Prefix(S);

    int i = 0;
    int j = 0;
    while (i < len_T) {
        while (S[j] != T[i] && j > 0) {
            j = prefixes[j - 1];
        }
        if (S[j] == T[i]) j++;
        if (j == 0) {
            printf("no");
            break;
        }
        ++i;
    }
    if (j != 0) printf("yes");
    
    free(prefixes);
    return 0;
}