#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dsort(char* str) {
	
    unsigned int count[26] = {0};
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        count[str[i] - 'a']++;
    }
	
    for (int i = 0; i < 26; i++) {
        while (count[i] != 0) {
            *str = (char)i + 'a';
            str++;
            count[i]--;
        }
    }
}

int main(){
    char* str;
    str = (char*)malloc(sizeof(char) * 1000001);
	
    scanf("%s", str);
    dsort(str);
    printf("%s", str);
	
    free(str);
    return 0;
}