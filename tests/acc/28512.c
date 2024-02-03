#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n == 1) {
        return 1;
    } else {
        int a = 0;
        int b = 1;
        int result = 0;

        for (int i = 2; i <= n; i++) {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
}

char *fibstr(int n) {
    int cur_fib = fibonacci(n);
    char *cur_str = (char*)malloc((cur_fib + 1) * sizeof(char));
    char *pre_str1 = (char*)malloc((cur_fib + 1) * sizeof(char));
    char *pre_str2 = (char*)malloc((cur_fib + 1) * sizeof(char));
    
    strcpy(cur_str, "");
    strcpy(pre_str1, "a");
    strcpy(pre_str2, "b");

    if (n <= 2) {
        strcpy(cur_str, (n == 1) ? pre_str1 : pre_str2);
    } else {
        int i = 2;
        while (i < n) {
            strcpy(cur_str, pre_str1);
            strcat(cur_str, pre_str2);
            strcpy(pre_str1, pre_str2);
            strcpy(pre_str2, cur_str);
            i++;
        }
    }

    free(pre_str1);
    free(pre_str2);
    return cur_str;
}

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    char *fib = fibstr(n);
    printf("%s\n", fib);
    free(fib);
    return 0;
}