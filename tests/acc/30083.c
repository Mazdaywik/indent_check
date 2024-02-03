#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Algorithm: https://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D1%80%D0%B5%D1%84%D0%B8%D0%BA%D1%81-%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D1%8F
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

//  Algorithm: https://e-maxx.ru/algo/prefix_function (Сжатие строки)
void printPeriodPrefixes(const char* s) {
    int* p = prefixFunction(s);
    int len_s = strlen(s);
    for (int i = 1; i < len_s; ++i) {
        int cur_len = i + 1;
        int t_len = cur_len - p[i];
        if (p[i] && cur_len % t_len == 0) {
            printf("%d %d\n", cur_len, cur_len / t_len);
        }
    }
    free(p);
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        printPeriodPrefixes(argv[1]);
    }
    return 0;
}
