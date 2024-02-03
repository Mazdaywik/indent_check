#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s) {
    unsigned long long r = strlen(s);
    int k = 0;
    int in_word = 0;
    char w;
    for (unsigned long long i = 0; i < r; i++) {
        w = s[i];
        if (w != ' ' && in_word == 0) {
            in_word = 1;
            k++;
        } else {
            if (w == ' ' && in_word == 1) {
                in_word = 0;
            }
        }
    }
    return k;
}

int main() {
    char s[1000];
    gets(s);
    int result = wcount(s);
    printf("%d\n", result);

    return 0;
}