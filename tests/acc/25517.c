#include <stdio.h>
#include <stdlib.h>

void dSort(char *str) {
    int count[26] = {0};
    int length = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z'){
            count[str[i] - 'a']++;
            length++;
        }
    }
  
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%c", 'a' + i);
        }
    }
    printf("\n");
}

int main() {
    char str[1000001];

    if (scanf("%s", str) != 1) {
        printf("\n");
        return 0;
    }

    dSort(str);

    return 0;
}