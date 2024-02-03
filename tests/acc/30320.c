#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int wcount(char *s) {
    int count = 0;
    bool inword = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            if (!inword) {
                count++;
                inword = true;
            }
        } 
	else inword = false;
    }
    return count;
}

int main() {
    char s[1000];
    fgets(s, 1000, stdin);
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
    printf("%d", wcount(s));
    return 0;
}
