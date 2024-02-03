#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Not enough arguments\n");
        return 1;
    }

    char *s = argv[1];
    char *t = argv[2];

    int lenS = strlen(s), lenT = strlen(t);
    int count[lenS];
    count[0] = 0;
    for (int k = 0, i = 1; i < lenS; ++i){
        while ((k > 0) && (s[i] != s[k]))
            k = count[k - 1];
        if (s[i] == s[k])
            k++;
        count[i] = k;
    }

    int indS = 0;
    for (int i = 0; i < lenT; i++) {
        if (indS == lenS) {
            indS = count[indS - 1];
            printf("%d ", i - lenS);
        }
        if (s[indS] == t[i]) {
            indS++;
            continue;
        }
        if (indS != 0) {
            indS = count[indS - 1];
            i--;
        }
    }

    if (indS == lenS) {
        printf("%d ", lenT - lenS);
    }

    return 0;
}
