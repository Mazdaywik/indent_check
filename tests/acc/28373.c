#include <stdio.h>
#include <ctype.h>

int wcount(char *s) {
    int wordCount = 0;
    int inWord = 0;
    while (*s != '\0') {
        if (isspace(*s)) {
            if (inWord) {
                wordCount++;
                inWord = 0;
            }
        } else {
            if (!inWord)
                inWord = 1;
        }
        s++;
    }
    if (inWord)
        wordCount++;
    return wordCount;
}

int main() {
    char buffer[1000];
    int i = 0;
    char c;
    while (i < 1000 - 1 && ((c = getchar()) != '\n'))
        buffer[i++] = c;
    buffer[i] = '\0';
    printf("%d", wcount(buffer));
    return 0;
}