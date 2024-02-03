#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 256 

void delta1(char *s, int *q) {
    int len = strlen(s);
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        q[i] = len;
    }
    for (int j = 0; j < len; j++) {
        q[(unsigned char)s[j]] = len - j - 1;
    }
}

void suffix(char *s, int *suff) {
    int len = strlen(s);
    suff[len - 1] = len;
    for (int i = len - 2; i >= 0; --i) {
        int j;
        for (j = i; j >= 0 && s[j] == s[len - 1 - i + j]; --j);
        suff[i] = i - j;
    }
}

void delta2(char *s, int *delta2) {
    int len = strlen(s);
    int suff[len];
    suffix(s, suff);
    for (int i = 0; i < len; ++i) {
        delta2[i] = len;
    }
    int j = 0;
    for (int i = len - 1; i >= 0; --i) {
        if (suff[i] == i + 1) {
            for (; j < len - 1 - i; ++j) {
                if (delta2[j] == len) {
                    delta2[j] = len - 1 - i;
                }
            }
        }
    }
    for (int i = 0; i <= len - 2; ++i) {
        delta2[len - 1 - suff[i]] = len - 1 - i;
    }
}

int max(int x1, int x2) {
    if (x1 > x2)
        return x1;
    else
        return x2;
}

void bmsubst(char *s, char *t) {
    int delta1_table[ALPHABET_SIZE];
    delta1(s, delta1_table);
    int len_s = strlen(s);
    int len_t = strlen(t);
    int delta2_table[len_s];
    delta2(s, delta2_table);
    int i = len_s - 1;
    while (i < len_t) {
        int j = len_s - 1;
        while (j >= 0 && s[j] == t[i - len_s + 1 + j]) {
            --j;
        }
        if (j < 0) {
            printf("%d ", i - len_s + 1);
            i += max(delta1_table[(unsigned char)t[i - len_s + 1]] - len_s + 1 + j, 1);
        } else {
            i += max(delta1_table[(unsigned char)t[i]] - len_s + 1 + j, delta2_table[j]);
        }
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("%s\n", argv[0]);
        return 1;
    }
    bmsubst(argv[1], argv[2]);
    return 0;
}