#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000000

int countWords(char* s) {
    int in_word, i, nwords;

    in_word = 0;
    nwords = 0;
    for (i = 0; s[i] != '\0'; ++i) {
        if (s[i] == ' ') {
            in_word = 0;
        } else if (!in_word) {
            ++nwords;
            in_word = 1;
        }
    }
    return nwords;
}

typedef struct PtrWord_ {
    char* ptr;
    int len;
} PtrWord;

void countSort(PtrWord* words, int number_words, int range) {
    int* count = (int*) malloc((range + 1) * sizeof(int));
    PtrWord* buffer = (PtrWord*) malloc(number_words * sizeof(PtrWord));
    int i;

    for (i = 0; i <= range; ++i) {
        count[i] = 0;
    }
    for (i = 0; i < number_words; ++i) {
        ++count[words[i].len];
    }
    for (i = 1; i <= range; ++i) {
        count[i] += count[i - 1];
    }
    for (i = number_words - 1; i >= 0; --i) {
        --count[words[i].len];
        buffer[count[words[i].len]] = words[i];
    }
    memcpy(words, buffer, number_words * sizeof(PtrWord));
    free(buffer);
    free(count);
}


int getPtrWords(PtrWord* pword, char* str) {
    int i, cur_len, max_len, in_word;
    PtrWord* pw = pword;

    in_word = 0;
    cur_len = 0;
    max_len = 0;

    for (i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            if (in_word) {
                max_len = (max_len < cur_len) ? cur_len : max_len;
                pw->len = cur_len;
                pw->ptr = str + i - cur_len;
                in_word = 0;
                ++pw;
            }
        } else {
            if (!in_word) {
                in_word = 1;
                cur_len = 1;
            } else {
                ++cur_len;
            }
        }
    }
    if (in_word) {
        max_len = (max_len < cur_len) ? cur_len : max_len;
        pw->len = cur_len;
        pw->ptr = str + i - cur_len;
    }
    return max_len;
}


void csort(char* src, char* dst) {
    int number_words, i, max_len;
    PtrWord* pwords;
    char* pdst;

    number_words = countWords(src);
    if (number_words == 0) {
        dst[0] = '\0';
        return;
    }

    pwords = (PtrWord*) malloc(number_words * sizeof(PtrWord));
    max_len = getPtrWords(pwords, src);
    countSort(pwords, number_words, max_len);

    pdst = dst;
    for (i = 0; i < number_words; ++i) {
        memcpy(pdst, pwords[i].ptr, pwords[i].len * sizeof(char));
        pdst += pwords[i].len;
        *pdst = ' ';
        ++pdst;
    }
    --pdst;
    *pdst = '\0';
    free(pwords);
}

int main() {
    char* src = (char*) malloc(MAXLEN * sizeof(char));
    char* dst = (char*) malloc(MAXLEN * sizeof(char));

    gets(src);
    csort(src, dst);
    puts(dst);

    free(src);
    free(dst);
    return 0;
}