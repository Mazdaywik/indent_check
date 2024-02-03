#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

static int wcount(char *s) {
    int count = 0;
    bool inword = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            if (!inword) {
                count++;
                inword = true;
            }
        } 
        else {
            inword = false;
        }
    }
    return count;
}

static void split(char *str, char *res[], int *count) {
    char *token = strtok(str, " ");
    *count = 0;

    while (token != NULL) {
        res[*count] = malloc(strlen(token) + 1);
        strcpy(res[*count], token);

        (*count)++;
        token = strtok(NULL, " ");
    }
}

void csort(char *src, char *dest) {
    int len = strlen(src);
    char *src_copy = malloc(len + 1);
    strcpy(src_copy, src);

    int wc = wcount(src_copy);

    char **words = (char **)malloc(wc * sizeof(char *));

    int total_len = 0;
    int count[wc];
    for (int i = 0; i < wc; i++) {
        count[i] = 0;
    }

    split(src_copy, words, &wc);

    for (int i = 0; i < wc - 1; i++) {
        int curr_word_len = strlen(words[i]);
        total_len += curr_word_len + 1;

        for (int j = i + 1; j < wc; j++) {
            int next_word_len = strlen(words[j]);

            if (curr_word_len > next_word_len) {
                count[i] += next_word_len + 1;
            }
            else {
                count[j] += curr_word_len + 1;
            }
        }
    }

    total_len += strlen(words[wc - 1]);

    for (int i = 0; i < wc; i++) {
        strcpy(dest + count[i], words[i]);
    }

    for (int i = 0; i < wc; i++) {
        if (count[i] != 0) {
            dest[count[i] - 1] = ' ';
        }
        free(words[i]);
    }

    free(words);
    dest[total_len] = '\0';

    free(src_copy);
}

int main() {
    char src[1000];
    fgets(src, sizeof(src), stdin);
    int n = strlen(src);
    if (n > 0 && src[n - 1] == '\n') {
        src[n - 1] = '\0';
    }
    char dest[2 * n];

    csort(src, dest);
    printf("%s\n", dest);

    return 0;
}
