#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(int argc, char* argv[]) {
    char* s = argv[1];
    char* t = argv[2];
    int n = strlen(s), m = strlen(t);
    int* table[128];
    for (int i = 0; i < 128; i++) {
        table[i] = (int*) malloc(n * sizeof(int));
    }
    int tmp[128];
    for (int i = 0; i < 128; i++) {
        tmp[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 128; j++) {
            table[j][i] = tmp[j];
        }
        tmp[s[i]] = i;
    }
    int ok = 1;
    for (int i = 0; i <= m - n; ) {
        int j = n - 1;
        while (j >= 0 && s[j] ==  t[i + j]) {
            j--;
        }
        if (j < 0) {
            printf("%d ", i);
            ok = 0;
            break;
        } else {
            if (j == 0) {
                i++;
            } else {
                i += j - table[t[i + j]][j];
            }
        }
    }
    if (ok) {
        printf("%d\n", m);
    }
    for (int i = 0; i < 128; i++) {
        free(table[i]);
    }
    return 0;
}