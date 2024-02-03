#include <stdio.h>
#include <stdlib.h>

int wcount2(char *s, int i, int wasSpace) {
    return s[i] == '\0' ? 0 : (s[i] != ' ' && wasSpace ? 1 + wcount2(s, i + 1, 0) \
    : (s[i] == ' ' ? wcount2(s, i + 1, 1) : wcount2(s, i + 1, 0)));
}

int wcount(char *s) {
    return wcount2(s, 0, 1);
}

int main() {
    char* s = malloc(1000 * sizeof(char));
    gets(s);
    printf("%d", wcount(s));
    free(s);
    return 0;
}