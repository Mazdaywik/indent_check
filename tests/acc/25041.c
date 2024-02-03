#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODES 256

void bmall(char* pattern, char* text) {
    int plen, tlen, find = 0, table[CODES], i;
    int ch, last_ch;

    plen = strlen(pattern);
    tlen = strlen(text);

    for (i = 0; i < CODES; ++i) {
        table[i] = plen;
    }
    for (i = 0; i + 1 < plen; ++i) {
        table[(int)pattern[i]] = plen - i - 1;
    }

    last_ch = pattern[plen - 1];
    i = 0;
    while (i + plen <= tlen) {
        ch = text[i + plen - 1];
        if (ch == last_ch) {
            if (memcmp(text + i, pattern, plen - 1) == 0) {
                printf("%d ", i);
                find = 1;
            }
        }
        i += table[ch];
    }
    if (find) {
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return 0;
    }
    bmall(argv[1], argv[2]);
	return 0;
}