#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wcount(char *s)
{
    int size =(int)strlen(s);
    s[size] = ' ';
    int count = 0;
    char last;
    int n1 = 0;
    if (s[0] == ' ') {
        last = ' ';
        n1 = 1;
    }
    for (int i = n1; i <= size; i++) {
        if ((s[i] == ' ') && (last != ' ') )
            count++;
        last = s[i];
    }
    return count;
}
int main(){
    char str[1500];
    gets(str);
    printf("%d", wcount(str));
    return 0;
}