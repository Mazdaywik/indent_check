#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char **s, int n) {
    
    int total_length = 0;
    for (int i = 0; i < n; i++) {
        total_length += strlen(s[i]);
    }

    
    char *result = (char *)malloc((total_length + 1) * sizeof(char));

   
    int index = 0;
    for (int i = 0; i < n; i++) {
        int length = strlen(s[i]);
        memcpy(result + index, s[i], length);
        index += length;
    }

    
    result[total_length] = '\0';

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    char **strings = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        char input[1000];
        scanf("%s", input);
        strings[i] = (char *)malloc((strlen(input) + 1) * sizeof(char));
        strcpy(strings[i], input);
    }

    
    char *result = concat(strings, n);

    printf("%s\n", result);

    free(result);
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
