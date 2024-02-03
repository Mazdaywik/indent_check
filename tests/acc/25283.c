#include<stdio.h>

int wcount(char *s){
        int g = 0;
        for(int i = 0; s[i] != '\0'; i++){
                if( ( (s[i] != ' ') && (s[i] != '\t') && (s[i] != '\n') )
                 && ((s[i + 1] == '\0') || (s[i + 1] == ' ') || (s[i + 1] == '\t') || (s[i + 1] == '\n'))) {
                        g++;
                }
        }
        return g;
}

int main(){
        char s[1001];
        fgets(s, 1001, stdin);

        printf("%d", wcount(s));
}