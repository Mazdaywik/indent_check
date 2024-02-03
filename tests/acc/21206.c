#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * concat(char **s, int n) {
    int length = 0, shift = 0;

    for (int i = 0; i < n; ++i) {
        length += strlen(s[i]);
    }

    char * result = (char *)calloc(length + 1, sizeof(char));
    for (int i = 0; i < n; ++i) {
        int curlen = strlen(s[i]);
        memcpy(result+shift, s[i], curlen);
        shift += curlen;
    }

    return result;
}

int main() {
    int n; scanf("%d", &n);
    char ** sarray = (char **)calloc(n * 1001, sizeof(char*));

    for (int i = 0; i < n; ++i) {   
        char * s = (char *)calloc(1001, sizeof(char));
        scanf("%s", s);
        sarray[i] = s;
    }

    char * result = concat(sarray, n);

    printf("%s\n", result);

    for (int i = 0; i < n; ++i) {
        free(sarray[i]);
    }

    free(sarray);
    free(result);

    return 0;
}