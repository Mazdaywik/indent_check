#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000000 

int main() {
    char str[MAX_SIZE + 1]; 
    int count[26] = {0};

    if (fgets(str, MAX_SIZE + 1, stdin) == NULL) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    size_t length = strlen(str);
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0';
        length--;
    }

    for (size_t i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            count[str[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%c", 'a' + i);
        }
    }
    printf("\n");

    return 0;
}
