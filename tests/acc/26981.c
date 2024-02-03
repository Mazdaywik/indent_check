#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

const int maxsz = (int)1e6 + 15;

int main(int argc, char *argv[]){
    char s[maxsz];
    int p[maxsz];
    int n = strlen(argv[1]), m = strlen(argv[2]);
    memcpy(s, argv[1], n);
    s[n] = '#';
    memcpy(s + n + 1, argv[2], m);
    p[0] = 0;
    for (int i = 1; i < n + m + 1; ++i) {
        int j = p[i - 1];
        while (s[i] != s[j] && j > 0) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
        if (p[i] == n){
            printf("%d ", i - n * 2);
        }
    }
    return 0;
}