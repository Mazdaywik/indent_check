#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

static void countSort(const char *words[], int n, int maxLen, const char *sortedWords[]) {
    int count[MAX_WORD_LENGTH + 1] = {0};
    const char *output[n];
    for (int i = 0; i < n; i++) {
        count[strlen(words[i])]++;
    }
    for (int i = 1; i <= maxLen; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[strlen(words[i])] - 1] = words[i];
        count[strlen(words[i])]--;
    }
    for (int i = 0; i < n; i++) {
        sortedWords[i] = output[i];
    }
}

void csort(const char *src, char *dest) {
    int n = 0, maxLen = 0;
    const char *words[MAX_WORDS];
    char temp_storage[strlen(src) + 1];
    const char *temp[MAX_WORDS];
    strcpy(temp_storage, src);
    char *word = strtok(temp_storage, " ");
    while (word != NULL) {
        words[n] = word;
        maxLen = (strlen(word) > maxLen) ? strlen(word) : maxLen;
        word = strtok(NULL, " ");
        if (n >= MAX_WORDS - 1) break;
        n++;
    }
    countSort(words, n, maxLen, temp);
    dest[0] = '\0';
    for (int i = 0; i < n; i++) {
        strcat(dest, temp[i]);
        if (i < n - 1) {
            strcat(dest, " ");
        }
    }
}

int main() {
    char src[10000]; 
    char dest[10000]; 
    fgets(src, sizeof(src), stdin);
    size_t len = strlen(src);
    if (len > 0 && src[len - 1] == '\n') {
        src[len - 1] = '\0';
    }
    csort(src, dest);
    printf("%s\n", dest);
    return 0;
}