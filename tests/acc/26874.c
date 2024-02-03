#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pref(const char *s, int prefixes[]) {
    int n = strlen(s);
    prefixes[0] = 0;
    int k = 0;

    for (int i = 1; i < n; i++) {
        while (k > 0 && s[k] != s[i]) {
            k = prefixes[k - 1];
        }
        if (s[k] == s[i]) {
            k++;
        }
        prefixes[i] = k;
    }
}

int main(int argc, char **argv) {

    char *s = argv[1];
    int n = strlen(s);
    int prefixes[n];
    
    pref(s, prefixes);

    for (int i = 1; i < n; i++) {
        int length = i + 1;
        int p = length - prefixes[i];
        if (prefixes[i] > 0 && length % p == 0) {
            printf("%d %d\n", length, length / p);
        }
    }

    return 0;
}