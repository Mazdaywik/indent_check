#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void csort(char *src, char *dest) {
    char* input[1000];
    int i = 0, j = 0, n = 0;

    while (src[i] != '\0') {
        j = 0;
        char* str = malloc(1000);

        while ((src[i + j] == ' ') || (src[i] == '\n')) {
            i++;
        }

        while ((src[i + j] != ' ') && (src[i + j] != '\n') && (src[i + j] != '\0')) {
            str[j] = src[i + j];
            j++;
        }

        str[j] = ' ';
        str[j + 1] = '\0';
        input[n] = str;
        i += j;
        n++;
    }

    int count[n];

    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    j = 0;

    while (j < n - 1) {
        int i = j + 1;
        while (i < n) {
            if (strlen(input[i]) < strlen(input[j])) {
                count[j]++;
            } else {
                count[i]++;
            }
            i++;
        }
        j++;
    }

    char* sorted[1000];

    for (int i = 0; i < n; i++) {
        sorted[count[i]] = input[i];
    }

    sorted[n - 1][strlen(sorted[n - 1]) - 1] = '\0';
    dest[0] = '\0';

    for (int i = 0; i < n; i++) {
        strcat(dest, sorted[i]);
        free(sorted[i]);
    }
}

int main() {
    char input[1000];
    char* dest = malloc(1000);

    fgets(input, 1000, stdin);
    csort(input, dest);

    printf("%s", dest);
    free(dest);
    return 0;
}
