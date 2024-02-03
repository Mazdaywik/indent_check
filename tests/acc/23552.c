#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 1000
#define WORDS_SIZE 100

void csort(char *src, char *dest) {
    int length = strlen(src);
    char * temp = (char *)calloc(length+1, sizeof(char));
    memcpy(temp, src, length*sizeof(char));

    int n = 0, size = WORDS_SIZE, max_length = 0, shift = 0;
    char ** words = (char **)calloc(size, sizeof(char*));
    int * lengths = (int *)calloc(size, sizeof(int));

    for (char * s = strtok(temp, " "); s != NULL; s = strtok(NULL, " ")) {
        lengths[n] = strlen(s);
        words[n] = (char *)calloc(lengths[n]+1, sizeof(char*));
        max_length = fmax(max_length, lengths[n]);
        memcpy(words[n], s, lengths[n]);

        ++n;

        if (n >= size) {
            size += WORDS_SIZE;
            words = realloc(words, sizeof(char*)*size);
            lengths = realloc(lengths, sizeof(int)*size);
        }
    }

    int * count = (int *)calloc(max_length, sizeof(int));
    int * b = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; ++i)
        ++count[lengths[i] - 1];

    for (int i = 1; i < max_length; ++i)
        count[i] += count[i-1];
    
    for (int i = n - 1; i >= 0; --i)
        b[--count[lengths[i] - 1]] = i;

    for (int i = 0; i < n; shift += lengths[b[i]] + 1, ++i) {
        memset(dest+shift, ' ', lengths[b[i]]+1);
        memcpy(dest+shift, words[b[i]], lengths[b[i]]);
    }

    dest[shift-1] = '\0';

    for (int i = 0; i < n; ++i)
        free(words[i]);

    free(b);
    free(words);
    free(lengths);
    free(count);
    free(temp);
}

char * read_line() {
    int buffer_size = BUFFER_SIZE, pos = 0;
    char * buffer = (char *)calloc(buffer_size, sizeof(char)), symb;

    while (1) {
        symb = getchar();
        if (symb == EOF || symb == '\n') {
            buffer[pos] = '\0';
            break;
        }

        buffer[pos++] = symb;

        if (pos >= buffer_size) {
            buffer_size += BUFFER_SIZE;
            buffer = (char *)realloc(buffer, buffer_size);
        }
    }

    return buffer;
}

int main() {
    char * src = read_line();
    char * dest = (char *)calloc(strlen(src)+1, sizeof(char));

    csort(src, dest);

    puts(dest);

    free(dest);
    free(src);

    return 0;
}