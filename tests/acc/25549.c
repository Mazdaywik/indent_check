#include<stdio.h>
#include<string.h>

void prefix(char* s, int* preffunc, int len){
        preffunc[0] = 0;
        int i = 1, t = 0;
        while(i < len){
                while((t > 0) && (s[t] != s[i])){
                        t = preffunc[t - 1];
                }
                if(s[t] == s[i]) t++;
                preffunc[i] = t;
                i++;
        }
}

int main(int argc, char** argv){
        char* s = argv[1];
        char* t = argv[2];
        size_t lens = strlen(s), lent = strlen(t);
//      printf("%ld %ld\n", strlen(s), strlen(t));
        char q[lens + lent + 2];

        for(int i = 0; i < lens;i++){
                q[i] = s[i];
        }
        q[strlen(s)] = '#';
        for(int i = lens + 1;i < lens + lent + 1; i++){
                q[i] = t[i - lens - 1];
        }
        q[lens + lent + 1] = '\0';
//      printf("%s\n", q);

        int len = strlen(q);
        int preffunc[len];
        prefix(q, preffunc, len);

        for(size_t i = 0;i < len;i++){
                if (preffunc[i] == strlen(s)){
                        printf("%ld ", i - lens * 2);
                }
        }
        return 0;
}

