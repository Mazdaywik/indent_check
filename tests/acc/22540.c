#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int delta(char * src, char * dest) {
    int ss = strlen(src), sd = strlen(dest), i = 0;
    for (i = 0; i < ss && strncmp(src+i, dest, fmin(ss-i, sd)); ++i);
    return sd + i - ss;
}

int superstr_rec(char * last, int size, int k, char ** s) {
    if (k == 0)
        return size;
    
    int mn = 1e9;
    for (int i = 0; k >> i; ++i)
        if (k & (1 << i))
            mn = fmin(mn, superstr_rec(s[i], delta(last, s[i]) + size, k ^ (1 << i), s));

    return mn;
}

int superstr(int n, char ** s) {
    return superstr_rec("", 0, (1LL << n) - 1, s);
}

int main() {
    int n; scanf("%d\n", &n);
    char ** s = (char **)calloc(n, sizeof(char*));

    for (int i = 0; i < n; ++i) {
        s[i] = (char *)calloc(1001, sizeof(char));
        scanf("%s", s[i]);
    }

    printf("%d\n", superstr(n, s));

    for (int i = 0; i < n; ++i)
        free(s[i]);
    free(s);

    return 0;
}