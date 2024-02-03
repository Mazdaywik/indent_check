#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char *concat(char **s, int n){
    int size = 0, diff = 0;
    for (int i = 0; i < n; i ++) {
        size += strlen(s[i]);
    }
    char *new = (char *)calloc(size + 1, sizeof(char));
    for (int i = 0, diff = 0; i < n; diff += strlen(s[i]), i++){
        strcpy(new + diff, s[i]);
    }
    return new;

}
int main(){
    int n;
    scanf("%d", &n);
    char *res, *s[n];
    for (int i = 0; i < n; i++){
        s[i] = (char *)malloc(1002 * sizeof(char));
        strcpy(s[i], "");
        scanf("%s", s[i]);
    }
    res = concat(s, n);
    printf("%s", res);
    for (int i = 0; i < n; i++){
        free(s[i]);
    }
    free(res);
   return 0;
}