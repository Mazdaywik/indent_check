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
        }
        if (s[indS] == t[i]) {
            indS++;
            continue;
        }
        int sdvig = 1;
        while (indS != 0 && s[indS] != t[i]) {
            indS = count[indS - 1];
            sdvig = 0;
        }
        i--;
        if(sdvig){
            printf("no");
            return 0;
        }
    }
    printf("yes");
    return 0;
}
