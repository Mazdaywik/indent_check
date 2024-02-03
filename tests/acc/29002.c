#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int wcount(char *s){
    int len = strlen(s);
    if((s[0] == ' ' || s[0] == '\n') && len == 1) return 0;
    int words = 0;
    for(int i = 0; i < len; i++){
        if((i == len - 1) && s[i] != ' '){
            if(s[i] != '\n' || s[i-1] != ' '){
                words += 1;
            }
            break;
        }
        if(s[i] != ' ' && s[i + 1] == ' '){
            words += 1;
        }
    }
    return words;
}

int main(int args, char **argv){
    char s[1001];
    fgets(s, 1001, stdin);
    int res = wcount(s);
    printf("%d", res);
    return 0;
}


