#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(char *str, size_t len){
    int p_arr[len];
    for(int i = 0; i < len; i++)
        p_arr[i] = 0;

    int t = 0;
    for(int i = 1; i < len; i++){

        while(t > 0 && str[t] != str[i]){
            t = p_arr[t - 1];
        }
        
        if(str[t] == str[i])
            t++;
        
        p_arr[i] = t;
    }

    for(int i = 1; i < len; i++){
        if(p_arr[i] > 0 && ((i + 1) % ((i + 1) - p_arr[i])) == 0){
            int length = i + 1;
            int count = (i + 1) / ((i + 1) - p_arr[i]);
            printf("%d %d\n", length, count);
        }
    }
}

int main(int argc, char **argv){
    char *str = argv[1];

    size_t len = strlen(str);
    prefix(str, len);

    return 0;
}