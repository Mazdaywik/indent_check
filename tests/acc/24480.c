#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void dsort(char *ss){
    int cnt[26] = {0};
	int len = strlen(ss);
    for (int i = 0;i<len;++i){
        cnt[ss[i]-'a']++;
    }
    for(int i = 0;i<26;++i){
        for(int j =0;j<cnt[i];++j){
            printf("%c",(char)(i+'a'));
        }
    }

}

int main(){
    char* ss;
    scanf("%m[^\n]",&ss);
    dsort(ss);
    free(ss);
    return 0;
}