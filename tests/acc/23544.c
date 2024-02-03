#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int wcount(char *s) {
    long len = strlen(s), i = 0, count = 0;
    if (s[0] == '\0') return 0;
    if (s[len - 1] != '\n') len++;
    while (i < len - 1) {
        if (s[i] != ' ') {
            while ((i < len - 1) && (s[i] != ' ')) {
                i++;
            }
            count++;
        }
        else i++;
    }
    return count;
}
int main(int argc, char **argv)
{
    char s[1001];
    fgets(s, 1001, stdin); 
    printf("%d", wcount(s));
    return 0;
}