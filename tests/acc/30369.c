#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char** s, int n)
{
    int total_size = 0;
    for (int i = 0; i < n; i++) {
        total_size += strlen(s[i]);
    }

    char* result = (char*)malloc(total_size + 1);
    result[0] = '\0';

    int offset = 0;
    for (int i = 0; i < n; i++) {
        int length = strlen(s[i]);
        memcpy(result + offset, s[i], length);
        offset += length;
    }

    result[total_size] = '\0';

    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    while (getchar() != '\n');

    if (n <= 0)
        return 0;

    char** strings = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        strings[i] = (char*)malloc(1002);
        fgets(strings[i], 1002, stdin);
        strings[i][strlen(strings[i]) - 1] = '\0';
    }

    char* temporary_string = concat(strings, n);
    printf("%s", temporary_string);

    for (int i = 0; i < n; i++)
        free(strings[i]);

    free(temporary_string);
    free(strings);

    return 0;
}