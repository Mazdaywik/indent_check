#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void csort(char *src, char *dest) {
    int cnt_words = 0;
    int n = strlen(src);
    for (int i = 0; i < n; ) {
        if (src[i] == ' ') {
            i++;
            continue;
        } else {
            int j = i;
            while (j < n && src[j] != ' ') {
                j++;
            }
            cnt_words++;
            i = j;
        }
    }
    char** words = (char**) malloc(cnt_words * sizeof(char*));
    int tmp_word = 0;
    int cnt_len[1001];
    for (int i = 0; i < 1001; i++) {
        cnt_len[i] = 0;
    }
    for (int i = 0; i < n; ) {
        if (src[i] == ' ') {
            i++;
            continue;
        } else {
            int j = i;
            while (j < n && src[j] != ' ') {
               j++;
            }
            words[tmp_word] = (char*) malloc((j - i + 1) * sizeof(char));
            j = i;
            while (j < n && src[j] != ' ') {
                words[tmp_word][j - i] = src[j];
                j++;
            }
            cnt_len[j - i]++;
            words[tmp_word][j - i] = '\0';
            tmp_word++;
            i = j;
        }
    }
    int* inds[1001];
    int tmp_inds[1001];
    for (int i = 0; i < 1001; i++) {
        tmp_inds[i] = 0;
        inds[i] = (int*) malloc(cnt_len[i] * sizeof(int));
    }
    for (int i = 0; i < cnt_words; i++) {
        inds[strlen(words[i])][tmp_inds[strlen(words[i])]] = i;
        tmp_inds[strlen(words[i])]++;
    }
    int ok = 0;
    int tmp_idx_res = 0;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < cnt_len[i]; j++) {
            if (ok) {
                dest[tmp_idx_res] = ' ';
                tmp_idx_res++;
            }
            ok = 1;
            for (int k = 0; k < i; k++) {
                dest[tmp_idx_res] = words[inds[i][j]][k];
                tmp_idx_res++;
            }
        }
    }
    dest[tmp_idx_res] = '\0';
    for (int i = 0; i < 1001; i++) {
        free(inds[i]);
    }
    for (int i = 0; i < cnt_words; i++) {
        free(words[i]);
    }
    free(words);
}

int main(int argc, char **argv) {
    char *src = (char*) malloc(1001 * sizeof(char));
    fgets(src, 1001, stdin);
    src[strlen(src) - 1] = '\0';
    char *dest = (char*) malloc(1001 * sizeof(char));
    csort(src, dest);
    printf("%s\n", dest);
    free(src);
    free(dest);
    return 0;
}