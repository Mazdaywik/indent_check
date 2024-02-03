#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    char* s = argv[1];
    char* t = argv[2];
    char* s_ = (char*) malloc((strlen(s) + 1 + strlen(t) + 1) * sizeof(char));
    int* pi = (int*) malloc((strlen(s) + 1 + strlen(t)) * sizeof(int));
    
    int len1 = strlen(s), len2 = strlen(t);
    for (int i = 0; i < len1; i++) {
        s_[i] = s[i];
    }
    s_[len1] = '#';
    for (int i = 0; i < len2; i++) {
        s_[len1 + 1 + i] = t[i];
    }
    s_[len1 + 1 + len2] = '\0';
    int len = strlen(s_);
    for (int i = 0; i < len; i++) {
        // printf("%d %d %d %d\n", i, len1, len2, len);
        pi[i] = 0;
    }
    
    for (int i = 1; i < len; i++) {
        int j = pi[i - 1];
        while (j > 0 && s_[i] != s_[j]) {
            j = pi[j - 1];
        }
        if (s_[i] == s_[j]) {
            j++;
        }
        pi[i] = j;
    }
    for (int i = 1; i < len; i++) {
        if (pi[i] == len1) {
            printf("%d\n", i - len1 - len1);
        }
    }
    free(s_);
    free(pi);
    return 0;
}