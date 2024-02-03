#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dsort(char *s, size_t len, char *ans){
    long count[26] = {0};

    for(long i = 0; i < len; i++){
        count[(int)s[i] - 97]++;
    }

    for(int i = 1; i < 26; i++){
        count[i] += count[i - 1];
    }

    for(long j = len - 1; j >= 0; j--){
        int key = ((int)s[j] - 97);
        long i = count[key] - 1;
        count[key]--;
        ans[i] = s[j];
    }

}

int main(){
    char s[1000003];
    fgets(s, 1000003, stdin);

    unsigned long len = strlen(s);
    char ans[len];

    dsort(s, len - 1, ans);

    ans[len - 1] = '\0';
    puts(ans);

    return 0;
}