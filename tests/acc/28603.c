#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define BUFFER_SIZE 1000

int wcount(char *s) {
    int count = 0;
    bool inWord = false;
    
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] != ' ' && !inWord) {
            inWord = true;
            count++;
        }

        if (s[i] == ' ') {
            inWord = false;
        }
    }

    return count;
}

int main() {
    char buffer[BUFFER_SIZE];

    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        return 1;
    }
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    int wordCount = wcount(buffer);
    printf("%d\n", wordCount);

    return 0;
}
