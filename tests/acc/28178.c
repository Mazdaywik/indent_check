#include <stdio.h>

int is_prefix(char *s, char *t) 
{
    for (int i = 0; t[i] != '\0'; i++) {
        int j = i;
        int res;
        while ((j >= 0) && (s[i - j] != '\0')) {
            res = 1;
            for (int a = j; a <= i; a++)
                if (t[a] != s[a - j]) {
                    res = 0;
                    break;
                }
            if (res)
                break;
            j--;
        }
        if (!res)
           return 0; 
    }
    return 1;
}

int main(int argc, char *argv[]) {
    char *s = argv[1];
    char *t = argv[2];
    if (is_prefix(s, t))
        printf("yes");
    else
        printf("no\n");
   return 0;
}