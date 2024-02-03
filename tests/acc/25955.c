#include <stdio.h>


int wcount(char *s) {
    int i = 0;
    int word_count = 0;
    while(s[i] != '\0') {
        if (((s[i] != '\n')&&(s[i]!= ' '))&&((s[i+1] == ' ')||(s[i+1] == '\n')||(s[i+1] == '\0'))) word_count++;
        i++;
    }
    return word_count;
}
int main() {
    char string[1001];
    fgets(string, 1001, stdin);
    printf("%d", wcount(string));
    return 0;
}