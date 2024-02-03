#include <stdio.h>
#include <string.h>

int wcount(char *str){
    int res = 0, i = 0;
   
    while (str[i] != '\0' && str[i] != '\n') {
        if(str[i]!=' ') {
            res++;
            while (str[i]!=' ' && str[i] != '\0' && str[i] != '\n')
                i++;
        }
        while (str[i]==' ' && str[i] != '\0' && str[i] != '\n')
            i++;
    }
    return res;
}

int main(int argc, char **argv)
{
    char s[2000] = {'\0'};
    fgets(s, 1002, stdin);
    printf("%d\n", wcount(s));
    return 0;
}