#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wcount(char *s){
	int words = 0;
	int length = strlen(s);
	int probel = 1;
	for (int i = 0; i < length; i++){
		if(s[i] == ' '){
			probel = 1;
		}
		else if((probel == 1) && (s[i] != ' ')){
			words = words + 1;
			probel = 0;
		}
	}
	return words;
}
int main(){
	char s[1000];
	gets(s);
	int words = wcount(s);
	printf("%d", words);
	return 0;
}