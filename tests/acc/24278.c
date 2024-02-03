#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
    char* s = argv[1];
    int n = strlen(s);
    int* p = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        p[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    for (int i = 1; i < n; i++) {
        int x = i + 1 - p[i];
        if ((i + 1) % x == 0  && (i + 1) / x != 1) {
            printf("%d %d\n", i + 1, (i + 1) / x);
        }
    }
    free(p);
    return 0;
}