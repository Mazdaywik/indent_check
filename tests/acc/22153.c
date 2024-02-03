#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[1000001];
    gets(s);
    int words[26];
    for (int i = 0; i < 26; i++) {
		words[i] = 0;
	}
    int j = 0, len, i = 1, k;
    len = strlen(s);
    while (j < len){
        words[((int) s[j]) - (int)('a')] += 1;
        j += 1;
    }
    while (i < 26){
        words[i] += words[i - 1];
        i += 1;
    }
    j = len - 1;
    char s2[1000001];
    while (j >= 0){
        k = ((int) s[j]) - (int)('a');
        i = words[k] - 1;
        words[k] = i;
        s2[i] = s[j];
        j -= 1;
    }
    for (int i = 0; i < len; i++){
        s[i] = s2[i];
    } 
	printf("%s\n", s);	   
}