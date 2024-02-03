#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void search(char* str, char* pattern){
    int found = 0;
    long str_len = strlen(str), pattern_len = strlen(pattern), shift = 0;
    char **delta = (char**)calloc(pattern_len, sizeof(char*));
    for (int i = 0; i < pattern_len; i++){
        delta[i] = (char *)calloc(256, sizeof(char));
    }
    for (int i = 0; i < pattern_len; i++){
        for (int j = 0; j < i; j++){
            delta[i][pattern[j]] = i - j;
        }
    }
    while (shift <= str_len - pattern_len){
        long pattern_at = -1;
        for (int i = pattern_len - 1; i >= 0; i--){
            if (str[i + shift] == pattern[i]){
                continue;
            }
            pattern_at = i;
            break;
        }
        if (pattern_at == -1){
            printf("%ld\n", shift);
            found = 1;
            break;
        }
        else{
            if (delta[pattern_at][str[shift + pattern_at]]){
                shift += delta[pattern_at][str[shift + pattern_at]];
            }
            else{
                shift += (pattern_at > 0) ? pattern_at : 1;
            }
        }
    }
    for (int i = 0; i < pattern_len; i++){
        free(delta[i]);
    }
    free(delta);
    if (!found){
        printf("%ld", str_len);
    }
}
int main(int argc, char* argv[]){
    if (argc != 3){
        return -1;
    }
    search(argv[2], argv[1]);
}