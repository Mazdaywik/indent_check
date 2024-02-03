    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>


    char *concat(char **s, int n){
        long long len = 0;
        for(int i = 0; i < n; i++){
            len += strlen(s[i]);
        }
        char *str = malloc((len + 1) * sizeof(char));
        int last = 0;
        for(int i = 0; i < n; i++){
            int l = strlen(s[i]);
            for(int j = 0; j < l; j++){
                str[last] = s[i][j];
                last++;
            }
        }
        str[last] = '\0';
        return str;
    }

    int main(int args, char **argv){
        int n = 0;
        scanf("%d", &n);
        char *strs[n];
        for(int i = 0; i < n; i++){
            char *s = malloc(1001 * sizeof(char));
            scanf("%s", s);
            strs[i] = s;
        }
        char *res = concat(strs, n);
        printf("%s", res);
        free(res);
        for(int i = 0; i < n; i++){
            free(strs[i]);
        }
        return 0;
    }
