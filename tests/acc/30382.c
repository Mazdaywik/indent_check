#include <stdio.h>
#include <string.h>

#define MAX 1000000

int main() {
    char str[MAX];
    int count[26] = {0}, i, j, k, len;

    scanf("%s", str);

    len = strlen(str);

    for (i = 0; i < len; i++) {
        count[str[i] - 'a']++;
    }

    for (i = 0, j = 0; i < 26; i++) {
        for (k = 0; k < count[i]; k++) {
            str[j++] = i + 'a';
        }
    }

    printf("%s\n", str);

    return 0;
}
