#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *prefix_f(char *s) {
    int len = strlen(s);
    int *res = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        res[i] = 0;
    }
    for (int i = 1; i < len; i++) {
        int t = res[i - 1];
        while (t > 0 && s[i] != s[t]) {
            t = res[t - 1];
        }
        if (s[i] == s[t]) {
            t++;
        }
        res[i] = t;
    }
    return res;
}

int main(int argc, char *argv[]) {
    char *text = argv[1];
    int len = strlen(text);
    int *prefix = prefix_f(text);
    for (int i = 0; i < len; i++) {
        if (prefix[i] > 0 && (i + 1) % ((i + 1) - prefix[i]) == 0) {
            int w = i + 1 - prefix[i];
            int q = (i + 1) / w;
            printf("%d %d\n", i + 1, q);
        }
    }
    free(prefix);

    return 0;
}