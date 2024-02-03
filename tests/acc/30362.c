#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 1001

void csort(char* src, char* dest) {
    char** words = (char**)malloc(sizeof(char*) * (BUFFER + 1));
    int word_count = 0;

    while (*src != '\0') {
        while (isspace(*src)) {
            src++;
        }
            
        if (*src != '\0') {
            char* start = src;
            while (*src != '\0' && !isspace(*src)) {
                src++;
            }

            int length = (int)(src - start);
            words[word_count] = (char*)malloc((length + 1) * sizeof(char));
            strncpy(words[word_count], start, length);
            words[word_count][length] = '\0';
            word_count++;
        }
    }

    words = (char**)realloc(words, word_count * sizeof(char*));

    int* counter = (int*)calloc(BUFFER + 1, sizeof(int));

    for (int i = 0; i < word_count - 1; i++)
        for (int j = i + 1; j < word_count; j++)
            strlen(words[j]) < strlen(words[i]) ? counter[i]++ : counter[j]++;

    int dest_index = 0;
    for (int i = 0; i < word_count; i++) {
        int j = 0;
        while (counter[j] != i) {
            j++;
        }
        char* wp = words[j];
        while (*wp != '\0') {
            dest[dest_index] = *wp;
            dest_index++;
            wp++;
        }
        if (word_count - i > 1) {
            dest[dest_index] = ' ';
            dest_index++;
        }
    }
    dest[dest_index] = '\0';

    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }
    free(words);
    free(counter);
}

int main(int argc, char** argv) {
    char* input = (char*)calloc(BUFFER, sizeof(char));
    char* output = (char*)calloc(BUFFER, sizeof(char));

    fgets(input, BUFFER, stdin);

    csort(input, output);
    printf("%s", output);

    free(input);
    free(output);
    return 0;
}