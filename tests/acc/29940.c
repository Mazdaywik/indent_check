#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  Algorithm: https://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D1%80%D0%B5%D1%84%D0%B8%D0%BA%D1%81-%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D1%8F
int* prefixFunction(const char* s) {
    int len_s = strlen(s);
    int* p = (int*)malloc(len_s * sizeof(int));
    p[0] = 0;
    for (int i = 1; i < len_s; ++i) {
        int k = p[i - 1];
        while (k && s[i] != s[k]) {
            k = p[k - 1];
        }
        if (s[i] == s[k]) {
            ++k;
        }
        p[i] = k;
    }
    return p;
}

//  Algoritm: https://e-maxx.ru/algo/prefix_function
//  (собственно префик функция и разработана под этот алгоритм)
void kmp(const char* pattern, const char* text) {
    int len_p = strlen(pattern);
    if (len_p == 0) {
        return;
    }
    int* p = prefixFunction(pattern);
    int k = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
        while (k && text[i] != pattern[k]) {
            k = p[k - 1];
        }
        if (text[i] == pattern[k]) {
            ++k;
        }
        if (k == len_p) {
            printf("%d ", i - k + 1);
        }
    }
    printf("\n");
    free(p);
}

int main(int argc, char* argv[]) {
    if (argc == 3) {
        kmp(argv[1], argv[2]);
    }
    return 0;
}
