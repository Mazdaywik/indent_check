#include <stdio.h>
#include <string.h>

void Prefix(char *s, int *pi) {
    int n = strlen(s), t = 0;
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        while (t > 0 && s[i] != s[t]) {
            t = pi[t - 1];
        }
        if (s[i] == s[t]) {
            t++;
        }
        pi[i] = t;
    }
}

int main(int argc, char *argv[]) {
    char *str = argv[1];
    int n = strlen(str);
    int pi[n];
    Prefix(str, pi);
    for (int i = 1; i < n; i++) {
        if (pi[i] > 0 && (i + 1) % (i + 1 - pi[i]) == 0)
            printf("%d %d\n", i + 1, (i + 1) / (i + 1 - pi[i]));
    }
    return 0;
}
