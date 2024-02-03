#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char **s, int n) {
    int total_length = 0;
    for (int i = 0; i < n; ++i) {
        total_length += strlen(s[i]);
    }
    char *result = (char *)malloc(total_length + 1);
    int position = 0;
    for (int i = 0; i < n; ++i) {
        strcpy(result + position, s[i]);
        position += strlen(s[i]);
    }
    result[total_length] = '\0';
    return result;
}

int main() {
    int num_strings;
    scanf("%d", &num_strings);
    char **strings = (char **)malloc(num_strings * sizeof(char *));
    for (int i = 0; i < num_strings; ++i) {
        strings[i] = (char *)malloc(1001 * sizeof(char)); // Предполагаем, что строки не превышают 1000 символов
        scanf("%s", strings[i]);
    }
    char *result = concat(strings, num_strings);
    printf("%s", result);
    for (int i = 0; i < num_strings; ++i) {
        free(strings[i]);
    }
    free(strings);
    free(result);

    return 0;
}
