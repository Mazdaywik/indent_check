#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int BMSubst(char *s, char *t, int len_s, int len_t, int size)
{
    int **de1;
    de1 = (int**) calloc(len_s, sizeof(int*));
    
    int a = 0;
    for (int i = 0; i < len_s; i++) {
        de1[i] = (int*) calloc(size, sizeof(int));
        while (a < size) {
            de1[i][a] = len_s;
            a++;
        }
    }
    
    int k = len_s - 1;
    while (k < len_t) {
        int i = len_s - 1;
        while (t[k] == s[i]) {
            if (i == 0) {
                for (int i = 0; i < len_s; ++i) {
                      free(de1[i]);
                }
                free(de1);
                return k;
            }
            i--;
            k--;
        }
        k = k + max(de1[i][t[k] - 33], len_s - i);
    }
    for (int i = 0; i < len_s; ++i) {
          free(de1[i]);
    }
    free(de1);
    return len_t;
}

int main(int argc, char **argv)
{
    char *s = argv[1];
    char *t = argv[2];
    
    size_t len_s = strlen(s);
    size_t len_t = strlen(t);
    
    int size = 126 - 33 + 1;
    
    printf("%d ", BMSubst(s, t, len_s, len_t, size));
    return 0;
}
