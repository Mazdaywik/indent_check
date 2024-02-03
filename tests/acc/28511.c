#include <stdio.h>
#include <string.h>

int wcount(char *s) {
    char inWord = 0;
    int cnt = 0;
    int nel = strlen(s);

    for (int i = 0; i < nel; i++) {
        if (s[i] != ' ') {
            inWord = 1;
        } else {
            if (inWord == 1) {
                cnt++;
                inWord = 0;
            }
        }
    }

    if (inWord == 1) {
        cnt++;
    }

    return cnt;
}

int main(int argc, char **argv) {
    char s[1000];
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    while (len > 0 && (s[len - 1] == ' ' || s[len - 1] == '\n')) {
        s[--len] = '\0';
    }

    printf("%d", wcount(s));
    return 0;
}