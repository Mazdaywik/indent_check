#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat(char **s, int n)
{
    long long len = 1;
    for (int i=0; i < n; i++) {
        len += strlen(s[i]);
    }
    char *new_str = malloc(sizeof(char) * len);
    new_str[0] = '\0';
    long long last = 0;
    for (int i=0; i<n; i++) {
        strcat(new_str + last, s[i]);
        last += strlen(s[i]);
    }
    return new_str;
}

int main() {
    int n;
    scanf("%d", &n);
    char **s = malloc(sizeof(char*) * n);
    for (int i=0; i<n; i++) {
        char *st = malloc(sizeof(char) * 1001);
        scanf("%s", st);
        s[i] = st;
    }
    char *d = concat(s, n);
    printf("%s", d);
    for (int i=0; i<n; i++) {
        free(s[i]);
    }
    free(s);
    free(d);
    return 0;
}
