#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dsort (char* src) {
    int count[26] = {0};
    int n = strlen(src);
    char D[n+1];
    int j = 0;
    while (j < n) {
        int k = src[j] - 97;
        count[k] += 1;
        ++j;
    }
    int i = 1;
    while (i < 26) {
        count[i] += count[i-1];
        ++i;
    }
    j = n - 1;
    while (j >= 0) {
        int k = src[j] - 97;
        i = count[k] - 1;
        count[k] = i;
        D[i] = src[j];
        --j;
    }

    for (int i = 0; i < n; i++) {
        printf("%c", D[i]);
    }
}

int main() {
    char *str = NULL;
    int ch;
    size_t size = 1000, len = 0;
    str = (char *)malloc(size*sizeof(char));

    while ((ch=getchar()) != EOF && ch != '\n') {
        if (len + 1 >= size)
        {
            size *= 2;
            str = realloc(str, sizeof(char)*size);
        }
        str[len++] = ch;
    }
    if (str != NULL) {
        str[len] = '\0';
        dsort(str);
        free(str);
    }

    return 0;
}