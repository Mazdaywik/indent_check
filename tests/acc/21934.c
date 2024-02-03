#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s){
    int i = 1, k = 0;

    if(strlen(s) == 0)
        return 0;

    while(s[i] != '\0'){
        if(s[i] == ' ' && s[i - 1] != ' ')
            k++;
        i++;
    }

    if(s[--i] != ' ')
        k++;
    
    return k;
}

int main(void){
    char *s = malloc(1000);
    int res;

    gets(s);
    res = wcount(s);
    printf("%d", res);

    free(s);

    return 0;
}