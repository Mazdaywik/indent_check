#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char s[1000000];
    for (int i = 0; i < 1000000; i++) {
        s[i] = '\0';
    }
    scanf("%s", &s);
    int cnt[26];
    for (int i = 0; i < 26; i++) {
        cnt[i] = 0;
    }
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            printf("%c", 'a' + i);
        }
    }
    return 0;
}