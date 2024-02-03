#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fibstr(int n) {
    if (n == 1) {
        char *result = (char *)malloc(2 * sizeof(char));
        strcpy(result, "a");
        return result;
    } else if (n == 2) {
        char *result = (char *)malloc(2 * sizeof(char));
        strcpy(result, "b");
        return result;
    } else {
        char *part1 = fibstr(n - 2);
        char *part2 = fibstr(n - 1);
        int len1 = strlen(part1);
        int len2 = strlen(part2);
        int len = len1 + len2 + 1;
        char *result = (char *)realloc(part1, (len + 1) * sizeof(char));
        memcpy(result + len1, part2, len2 + 1);
        
        free(part2);
        
        return result;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char *result = fibstr(n);
    printf("%s", result);
    free(result);
    return 0;
}