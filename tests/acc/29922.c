#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static int getWord(char* str, char* dest, int i){
    memset(dest, 0, strlen(dest));
    int j = 0;
    while (i < strlen(str) && str[i] != ' '){
        dest[j] = str[i];
        j++;
        i++;
    }
    while (i < strlen(str) && str[i] == ' '){
        i++;
    }
    return i;
}
static void concat(char *src, char* dest){
    int len = strlen(dest);
    for (int j = 0; j < strlen(src); j++){
        dest[len] = src[j];
        len++;
    }
    dest[len] = '\0';
}
void csort(char* src, char* dest2){
    char *dest = (char *)calloc(2000, sizeof(char));
    char **words = (char**)calloc(200, sizeof(char*));
    for (int i = 0; i < 200; i++){
        words[i] = (char*)calloc(500, sizeof(char));
    }
    int i = 0;
    char space[2] = {' ', 0};
    char* newWord = (char*)calloc(500, sizeof(char));
    while (i = getWord(src, newWord, i), strlen(newWord) > 0){
        if (strlen(words[strlen(newWord) - 1])) { concat(space, words[strlen(newWord) - 1]); };
        concat(newWord, words[strlen(newWord) - 1]);
    }
    free(newWord);
    for (int i = 0; i < 200; i++){
        concat(words[i], dest);
        if (strlen(words[i])){
            concat(space, dest);
        }
        free(words[i]);
    }
    dest[strlen(dest) - 1] = 0;
    free(words);
    for (int i = 0; i < strlen(dest); i++){
        dest2[i] = dest[i];
    }
    dest2[strlen(dest)] = 0;
    free(dest);
}

int main(){
    char *str = (char *)calloc(10001, sizeof(char)), *ans = (char *)calloc(10001, sizeof(char));
    fgets(str, 10001, stdin);
    str[strlen(str) - 1] = '\0';
    csort(str, ans);
    ans[strlen(ans)] = '\0';
    printf("%s", ans);
    free(str);
    free(ans);
}