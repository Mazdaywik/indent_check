#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    char *s = argv[1];
    char *t = argv[2];
    int len1 = strlen(s), len2 = strlen(t);
    char *p = (char*) malloc((len1 + 1 + len2 + 1) * sizeof(char));
    for (int i = 0; i < len1; i++) {
        p[i] = s[i];
    }
    p[len1] = '#';
    for (int i = 0; i < len2; i++) {
        p[len1 + 1 + i] = t[i];
    }
    p[len1 + 1 + len2] = '\0';
    int n = strlen(p);
    int *pi = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        pi[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
        }
        pi[i] = j;
    }
    int *cann = (int*) malloc((len2 + 1) * sizeof(int));
    cann[0] = 1;
    for (int i = 1; i <= len2; i++) {
        cann[i] = 0;
        int j = pi[i + len1 - 1];
        while (1) {
            int k = j;
            if (p[i + len1] == p[j]) {
                k++;
                if (cann[i - k]) {
                    cann[i] = 1;
                    break;
                }
            }
            
            if (j == 0) {
                break;
            }
            j = pi[j - 1];
        }
    }
    if (cann[len2]) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    free(p);
    free(pi);
    free(cann);
}