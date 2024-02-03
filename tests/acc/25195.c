#include <string.h>
#include <stdio.h>

int wcount(char *s)
{
    int counter = 0, lock = 1;
    for (int i=0; s[i]!='\0'; i++) {
        if (s[i] == ' ') {
            lock = 1;
        }
        else
        if (lock) {
            counter++;
            lock = 0;
        }
    }
    return counter;
}

int main() {
    char s[1001];
    fgets(s, 1001, stdin);
    s[strlen(s)-1] = '\0';
    int n = wcount(s);
    printf("%d", n);
    return 0;
}