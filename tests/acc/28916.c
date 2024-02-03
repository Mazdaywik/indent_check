#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void csort(char *src, char *dest) {
    int word_count = 0;
    char *words[50000];
    char str[strlen(src)];
    strcpy(str, src);
    char *token = strtok(str, "\n");
    token = strtok(str, " ");
    while (token != NULL) {
        words[word_count] = token;
        word_count++;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < word_count - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                swap(&words[j], &words[j + 1]);
            }
        }
    }

    int pos = 0;
    for (int i = 0; i < word_count; i++) {
        strcpy(&dest[pos], words[i]);
        pos += strlen(words[i]);
        dest[pos] = ' ';
        pos++;
    }
    dest[pos - 1] = '\0';
}

int main() {
    char src[100000] = "";
    fgets(src, 100000, stdin);
    
    char dest[strlen(src)];

    csort(src, dest);
    printf("%s\n", dest);
    
    return 0;
}