#include <stdio.h>
#include <string.h>

#define MAX_LETTERS 26 

void sortLetters(const char *str) {
    int count[MAX_LETTERS] = {0};
    int len = strlen(str); 
    for (int i = 0; i < len; i++) {
        count[str[i] - 'a']++;
    }
    for (int i = 0; i < MAX_LETTERS; i++) {
        for (int j = 0; j < count[i]; j++) {
            putchar('a' + i);
        }
    }
}

int main() {
    char str[1000000]; 
    scanf("%s", str); 
    sortLetters(str);
    putchar('\n');   
    return 0;
}