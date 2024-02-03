#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* a;
char* b;

char *fibstr(int n) {
    if (n == 1) {
        a = (char*) malloc(2 * sizeof(char));
        b = (char*) malloc(2 * sizeof(char));
        b[0] = 'a';
        b[1] = '\0';
        free(a);
        return b;
    }
    if (n == 2) {
        a = (char*) malloc(2 * sizeof(char));
        b = (char*) malloc(2 * sizeof(char));
        b[0] = 'b';
        b[1] = '\0';
        free(a);
        return b;
    }
    int f1 = 1, f2 = 1;
    for (int i = 0; i < n - 2; i++) {
        int f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    a = (char*) malloc((f2 + 1) * sizeof(char));
    b = (char*) malloc((f2 + 1) * sizeof(char));
    a[0] = 'a';
    b[0] = 'b';
    a[1] = '\0';
    b[1] = '\0';
    f1 = 1, f2 = 1;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < f2; j++) {
            a[f1 + j] = b[j];
        }
        a[f1 + f2] = '\0';
        char tmp = *b;
        *b = *a;
        *a = tmp;
        int f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    free(a);
    return b;
}

int main()
{
    int n; 
    scanf("%d", &n);
    char* s = fibstr(n);
    printf("%s", s);
    free(b);
    return 0;
}