#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))
const int maxsz = (int)1e6 + 10000;

int main(int argc, char *argv[]){
    char s[maxsz];
    int z[maxsz], l = 0, r = 0;
    int n = strlen(argv[1]), m = strlen(argv[2]);
    memcpy(s, argv[1], n);
    s[n] = '#';
    memcpy(s + n + 1, argv[2], m);

    for (int i = 0; i < maxsz; ++i){
        z[i] = 0;
    }
    for (int i = 1; i < n + m + 1; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < (n + m + 1) && s[z[i]] == s[i + z[i]]) {
            z[i] += 1;
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    for (int i = n + 1; i < n + m + 1; ++i) {
        z[i] = max(z[i - 1] - 1, z[i]);
        if (z[i] == 0) {
            printf("no");
            return 0;
        }
    }
    printf("yes");
    return 0;
}