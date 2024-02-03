#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Not enough arguments\n");
        return 1;
    }

    char *s = argv[1];
    char *t = argv[2];

    int lenS = strlen(s), lenT = strlen(t);

    int **remoteness = malloc(lenS * sizeof(int*));
    for (int i = 0; i < lenS; i++) {
        remoteness[i] = malloc(143 * sizeof(int));
        for (int j = 0; j < 143; j++) {
            remoteness[i][j] = i + 1;
        }
    }

    for (int i = 0; i < lenS; i++) {
        for (int j = i + 1; j < lenS && s[i] != s[j]; j++) {
            remoteness[j][s[i] - 33] = j - i;
        }
    }
    int i = 0;
    for (int j = 0, k = lenS - 1; j <= k && i < lenT - lenS + 1 ; j++, k--) {
        if (t[i + j] != s[j]) {
            i += remoteness[j][t[i + j] - 33];
            j = -1;
            k = lenS;
            continue;
        }
        if (t[i + k] != s[k]) {
            i += remoteness[k][t[i + k] - 33];
            j = -1;
            k = lenS;
            continue;
        }
    }
    if (i < lenT - lenS + 1) {
        printf("%d", i);
    }else{
        printf("%d", lenT);
    }
    for(int i = 0 ; i < lenS; i++)
        free(remoteness[i]);
    free(remoteness);
    return 0;
}
