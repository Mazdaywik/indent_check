#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>


char *concat(char **s, int n){
    int total = 0;
    for (int i = 0; i < n; ++i){
        total += strlen(s[i]);
    }
    char *ans = malloc(sizeof(char) * (total + 1));
    ans[total] = '\0';
    total = 0;
    for (size_t i = 0; i < n; ++i) {
        int len = strlen(s[i]);
        memmove(ans + total, s[i], len);
        total += len;
    }
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    char **mass = malloc(sizeof(char*) * n);
    for (int i = 0; i < n; ++i) {
        mass[i] = (char *)malloc(1001);
        scanf("%s", mass[i]);
    }
    char *res = concat(mass, n);
    printf("%s", res);
    free(res);
    for (size_t i = 0; i < n; ++i) {
        free(mass[i]);
    }
    free(mass);
    return 0;
}