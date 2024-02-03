#include<stdio.h>
#include<stdlib.h>
int wcount(char *s){
    int i = 0, c = 0, isWord = 0;
    while (s[i] != '\n' && s[i] != '\0'){
        if (s[i] != ' '){
            if (!isWord){
                c++;
                isWord = 1;
            }
        }
        else if (isWord){
            isWord = 0;
        }
        i++;
    }
    return c;
}
int main(){
    char *str = (char*)malloc(1200);
    fgets(str, 1200, stdin);
    printf("%d", wcount(str));
    free(str);
}