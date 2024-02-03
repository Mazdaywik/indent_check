#include <stdio.h>
#include <string.h>

void prefix(char* s, int* preffunc, int len) {
    preffunc[0] = 0;
    int i = 1, t = 0;

    while (i < len) {
        while ((t > 0) && (s[t] != s[i])) {
            t = preffunc[t - 1];
        }

        if (s[t] == s[i])
            t++;

        preffunc[i] = t;
        i++;
    }
}

int main(int argc, char** argv) {
    char* s = argv[1];
    size_t len = strlen(s);
    int preffunc[len];

    prefix(s, preffunc, len);

    for (size_t i = 0; i < len; i++) {
        int n = i + 1;
        int pref = preffunc[i];

        for (int j = 1; (j < pref + 1) && (j < n + 1); j++) {
            if ((pref % j == 0) && (n - j == pref)) {
                printf("%d %d\n", n, n / j);
            }
        }
    }

    return 0;
}
