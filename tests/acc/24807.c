#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char** s, int n) {
    if (n <= 0) {
        char *empty_str = malloc(1);
        if (empty_str == NULL) {
            return NULL;
        }
        empty_str[0] = '\0';
        return empty_str;
    }

    size_t total_length = 0;
    for (int i = 0; i < n; i++) {
        total_length += strlen(s[i]);
    }

    char* result = malloc(total_length + 1);
    if (result == NULL) {
        return NULL;
    }

    char* current_position = result;
    for (int i = 0; i < n; i++) {
        strcpy(current_position, s[i]);
        current_position += strlen(s[i]);
    }

    return result;
}

int main() {
    int string_count;
    scanf("%d", &string_count);

    if (string_count <= 0) {
        return 0;
    }

    char** string_array = malloc(sizeof(char*) * string_count);
    if (string_array == NULL) {
        return 1;
    }

    for (int index = 0; index < string_count; ++index) {
        string_array[index] = malloc(sizeof(char) * 100);
        if (string_array[index] == NULL) {
            for (int j = 0; j < index; j++) {
                free(string_array[j]);
            }
            free(string_array);
            return 1;
        }
        scanf("%99s", string_array[index]);
    }

    char* combined_string = concat(string_array, string_count);
    if (combined_string == NULL) {
        for (int i = 0; i < string_count; i++) {
            free(string_array[i]);
        }
        free(string_array);
        return 1;
    }

    printf("%s\n", combined_string);

    free(combined_string);
    for (int index = 0; index < string_count; ++index) {
        free(string_array[index]);
    }
    free(string_array);

    return 0;
}
