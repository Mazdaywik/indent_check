#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *fibstr(int n) { 
    long sumlen = 0, fiblen[n], i;
    if (n < 1) return NULL;
    fiblen[0] = 1; 
    fiblen[1] = 1; 
    for (i = 2; i < n; i++) { 
        fiblen[i] = fiblen[i-1] + fiblen[i-2]; 
    } 
    sumlen = fiblen[n-1]; 
    char *s_prev = malloc(sumlen + 1), *s_next = malloc(sumlen + 1), *temp; 
    strcpy(s_prev ,"a");
    strcpy(s_next ,"b");
    for (i = 2; i < n; i++) {
        temp = s_next; 
        strcat(s_prev, s_next); 
        s_next = s_prev; 
        s_prev = temp;
    } 
    if (n == 1) {
        free(s_next);
        return s_prev; 
    } 
    else { 
        free(s_prev);
        return s_next; 
    } 
}
int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    char *str = fibstr(n);
    printf("%s", str);
    free(str);
    return 0;
}