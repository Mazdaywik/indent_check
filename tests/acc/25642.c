#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int key(char *s) {
    return strlen(s);
}

void csort(char *src, char *dest) {
    int n = strlen(src), i, j, k = 0, p;
    char *temp;
    char **s = malloc(10000 * sizeof(char*));
    for (i = 0; i < 10000; i++) {
        s[i] = malloc(n + 1);
    }
    i = 0;
    if (src[n - 1] != '\n') p = n;
    else p = n - 1;
    while (i < n - 1) {
        if (src[i] != ' ') {
            j = 0;
            while ((i < p) && (src[i] != ' ')) {
                s[k][j] = src[i];
                i++;
                j++;
            }
            s[k][j] = '\0';
            k++;
        } 
        else {
            i++;
        }
    }

    int count[k];
    for (i = 0; i < k; i++) {
        count[i] = 0;
    }

    for (j = 0; j < k - 1; j++) {
        for (i = j + 1; i < k; i++) {
            if (key(s[i]) < key(s[j])) {
                count[j] += 1;
            } else {
                count[i] += 1;
            }
        }
    }

    char **s_new = malloc(k * sizeof(char*));
    for (i = 0; i < k; i++) {
        s_new[count[i]] = s[i];
    }
    dest[0] = '\0';
    for (i = 0; i < k - 1; i++) {
        strcat(dest, s_new[i]);
        strcat(dest, " ");
    }
    strcat(dest, s_new[k - 1]);
    for (i = 0; i < 10000; i++) {
        free(s[i]);
    }
    free(s);
    free(s_new);
}

int main(int argc, char **argv) {
    char st[10000] = "";
    fgets(st, 10000, stdin);
    char *dest = malloc(strlen(st) + 1);
    csort(st, dest);
    printf("%s\n", dest);
    free(dest);
    return 0;
}