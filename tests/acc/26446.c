#include<stdio.h>
#include<string.h>
void search(char* str, char* pattern){
    long str_len = strlen(str), pattern_len = strlen(pattern), shift = 0;
    long bad_chars[256] = {0};
    for (int i = 0; i < pattern_len; i++){
        bad_chars[pattern[i]] = i + 1;
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
            shift += 1;
        }
        else{
            shift += (pattern_at - bad_chars[str[shift + pattern_at]] > 1) ? pattern_at - bad_chars[str[shift + pattern_at]] : 1;
        }
    }
}
int main(int argc, char* argv[]){
    if (argc != 3){
        return -1;
    }
    search(argv[2], argv[1]);
}