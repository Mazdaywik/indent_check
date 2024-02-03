#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char **s, int n) {
    int sum_len = 0;
    for (int i = 0; i < n; i++) sum_len += strlen(s[i]);
    char *new_str = (char*)malloc((sum_len+1) * sizeof(char));
    memset(new_str, 0, (sum_len + 1) * sizeof(char));
    char *current_position = new_str;
    for (int i = 0; i < n; i++) {
        strcpy(current_position, s[i]);
        current_position += strlen(s[i]);
    }
    return new_str;
}

int main() {
    int max_len_str = 1000;
    int n;
    scanf("%d", &n);
    char **str = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        str[i] = (char*)malloc(max_len_str * sizeof(char));
        scanf("%s", str[i]);
    }
    char* result = concat(str, n);
    printf("%s", result);
    for (int i = 0; i < n; i++) free(str[i]);
    free(str);
    free(result);
    return 0;
}