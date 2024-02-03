#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int compare_lengths(size_t a, size_t b) {
    return a - b;
}

static int tokenize_and_count(char *str, char ***tokens) {
    int count = 0;
    char *current = str;
    while (*current != '\0') {
        if (!isspace(*current)) {
            char *start = current;
            while (*current != '\0' && !isspace(*current))
                current++;
            int length = (int) (current - start);
            *tokens = realloc(*tokens, (count + 1) * sizeof(char *));
            (*tokens)[count] = malloc((length + 1) * sizeof(char));
            strncpy((*tokens)[count], start, length);
            (*tokens)[count][length] = '\0';
            count++;
        } else {
            current++;
        }
    }
    return count;
}

static void reconstruct_sorted_string(int count, int *indices, char **tokens, char *destination) {
    int dest_index = 0;
    for (int i = 0; i < count; ++i) {
        int j = 0;
        while (indices[j] != i)
            j++;
        strcpy(destination + dest_index, tokens[j]);
        dest_index += strlen(tokens[j]);
        if (i + 1 != count) {
            destination[dest_index] = ' ';
            dest_index++;
        }
    }
    destination[dest_index] = '\0';
}

void csort(char *src, char *dest) {
    char **tokens = NULL;
    int count = tokenize_and_count(src, &tokens);
    if (count == 0)
        return;
    int *indices = calloc(count, sizeof(int));
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j)
            indices[(compare_lengths(strlen(tokens[i]), strlen(tokens[j])) <= 0) ? j : i]++;
    }
    reconstruct_sorted_string(count, indices, tokens, dest);
    for (int i = 0; i < count; ++i)
        free(tokens[i]);
    free(tokens);
    free(indices);
}

int main() {
    char input_str[1000];
    fgets(input_str, sizeof(input_str), stdin);
    char *result = calloc(strlen(input_str), sizeof(char));
    csort(input_str, result);
    puts(result);
    free(result);
    return 0;
}
