#include <stdio.h>

int main() {
    int counter[26] = {0};
    int c;
    while ((c = getc(stdin)) != '\n')
        counter[c - 'a']++;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < counter[i]; j++)
            putc('a' + i, stdout);
    return 0;
}