#include <stdio.h>
#include <string.h>

void countingSort(char str[], int size) {
    int count[26] = {0};
    for (int i = 0; i < size; i++)
        count[str[i] - 'a']++;
    int index = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < count[i]; j++)
            str[index++] = 'a' + i;
    }
}

int main() {
    char str[1000001];
    fgets(str, 1000001, stdin);
    str[strcspn(str, "\n")] = '\0';
    int size = strlen(str);
    countingSort(str, size);
    printf("%s", str);
    return 0;
}