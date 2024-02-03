#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

void distributionSort(char* str) {
    int count[ALPHABET_SIZE] = { 0 };
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        count[str[i] - 'a']++;
    }

    int index = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        while (count[i] > 0) {
            str[index++] = 'a' + i;
            count[i]--;
        }
    }
}

int main() {
    char str[1000001];

    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[--len] = '\0';
    }

    distributionSort(str);

    printf("%s\n", str);

    return 0;
}