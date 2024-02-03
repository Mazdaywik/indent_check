#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* Prefix(char* s) {
    size_t len = strlen(s);
    int t = 0;
    int* p = (int*) malloc(len * sizeof(int));
    p[0] = t;
    int i = 1;
    while (i < len) {
        while (t > 0 && s[t] != s[i]) {
            t = p[t-1];
        }
        if (s[t] == s[i]) ++t;
        p[i] = t;
        ++i;
    }
    return p;
}

int main(int argc, char** argv) {
    char* s = argv[1];
    int* p = Prefix(s);
    size_t len = strlen(s);
    int n = 2;
    while (n <= len) {
        int k = n/(n - p[n-1]);
        if (k * (n - p[n-1]) == n) {
            if (p[n-1] > 0) printf("%d %d\n", n, k);
        }
        ++n;
    }
    free(p);
    return 0;
}