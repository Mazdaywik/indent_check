#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char **s, int n) {
    int total_length = 0;
    for (int i = 0; i < n; ++i)
        total_length += strlen(s[i]);

    char *result = malloc(total_length + 1);
    char *current_position = result;

    for (int i = 0; i < n; ++i) {
        char *current_string = s[i];
        while (*current_string)
            *current_position++ = *current_string++;
    }

    *current_position = '\0';

    return result;
}

int main() {
    int num_strings;
    scanf("%d", &num_strings);

    char **strings = malloc(num_strings * sizeof(char *));

    for (int i = 0; i < num_strings; ++i) {
        strings[i] = malloc(1001);
        scanf("%s", strings[i]);
    }

    char *result = concat(strings, num_strings);

    printf("%s\n", result);

    free(result);
    for (int i = 0; i < num_strings; ++i)
        free(strings[i]);
    free(strings);

    return 0;
}
