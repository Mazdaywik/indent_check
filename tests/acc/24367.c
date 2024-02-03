#include <stdio.h>
#include <string.h>

void sort(char s[], int n) {
    int dict[26] = {0};

    for (int i = 0; i < n; i++) {
        dict[(int)s[i] - 'a']++;
    }

    int k = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < dict[i]; j++) {
            s[k] = 'a' + i;
            k++;
        }
    }
}

int main() {
    char str[1000002];
    scanf("%s", str);

    int n = strlen(str);

    sort(str, n);

    printf("%s\n", str);

    return 0;
}