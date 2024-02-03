#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readstr(char* str) {

    scanf("%s", str);

    str[strlen(str)] = '\0';

}


char *concat(char **s, int n) {

    unsigned int total_sum = 0;

    for (int i = 0; i < n; i++) 
        total_sum += strlen(s[i]);

    char* result = (char*)calloc((total_sum + 1), sizeof(char)); 
    
    for (int i = 0, k = 0; i < n; i++) {
        
        for (int j = 0; s[i][j] != 0; j++, k++) {
            
            result[k] = s[i][j];
        }
    }
    
    result[total_sum] = '\0';
    
    return result;

}

int main(int argc, char **argv) {
    
    int count;
    scanf("%d", &count);

    char** user_strings = (char **)malloc(count * sizeof(char*));

    for (int i = 0; i < count; i++) {

        user_strings[i] = NULL;

        char buffer[1001];

        readstr(buffer);

        user_strings[i] = malloc((strlen(buffer) + 1) * sizeof(char));

        strcpy(user_strings[i], buffer);
        
    }

    char* answer = concat(user_strings, count);

    printf("%s", answer);

    free(answer);

    for (int i = 0; i < count; i++)
        free(user_strings[i]);

    free(user_strings);

    return 0;
}