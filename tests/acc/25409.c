#include<stdio.h>
#include<string.h>
int main(){
        char s[1000011];
        fgets(s, 1000011, stdin);
        int len = strlen(s) - 1;
        int i,  keys[27];
        for(i = 0; i < 27; i++){
                keys[i] = 0;
        }
        for(i = 0; (s[i] != '\n') && (s[i] != '\0');i++){
                keys[s[i] - 97] += 1;
        }
        char news[len];
        int g = 0;
        for(i = 0;i < 27; i++){
                int t = keys[i];
                for(int j = 0;j < t;j++){
                        news[j + g] = i + 97;
                        }
                g += t;
        }
        for(i = 0;i < len;i++) printf("%c", news[i]);
        return 0;
}