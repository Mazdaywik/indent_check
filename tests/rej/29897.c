#include <stdio.h>
#include <string.h>

int wcount(char *s) {
 int count = 0;
 int len = strlen(s);
 int i = 0;
 while (i < len) {
    if (s[i] != ' ' && (i == len - 1 || s[i + 1] == ' ')) {
      count++;
    }
    i++;
 }
 return count;
}

int main() {
 char s[1000];
 fgets(s, sizeof(s), stdin);
 printf("%d", wcount(s));
 return 0;
}