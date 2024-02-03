#include <stdio.h>

int wcount(char *s) {
    int count = 0;
    int is_word = 0; 

    while (*s != '\0') {
        if (*s == ' ' || *s == '\t' || *s == '\n') {
            is_word = 0; 
        } else {
            if (!is_word) {
                count++; 
                is_word = 1; 
            }
        }
        s++;
    }

    return count;
}

int main() {
    char buffer[1000];
    fgets(buffer, sizeof(buffer), stdin);
    int result = wcount(buffer);
    printf("%d\n", result);;

    return 0;
}