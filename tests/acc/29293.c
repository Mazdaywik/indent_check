#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* computeLPSArray(char* pattern) {
    int pattern_len = strlen(pattern);
    int* lps = (int*)malloc(pattern_len * sizeof(int));

    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < pattern_len) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void kmpSearch(char* pattern, char* text) {
    int pattern_len = strlen(pattern);
    int text_len = strlen(text);

    int* lps = computeLPSArray(pattern);

    int i = 0, j = 0;

    while (i < text_len) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == pattern_len) {
            printf("%d ", i - j);

            j = lps[j - 1];
        }

        else if (i < text_len && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    free(lps);
}

int main(int argc, char* argv[]) {
    if (argc != 3) 
    {
        return 1;
    }

    char* pattern = argv[1];
    char* text = argv[2];

    kmpSearch(pattern, text);

    return 0;
}
