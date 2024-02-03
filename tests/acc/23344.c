#include <stdio.h>
#include <string.h>
int main(){
	unsigned long count[26];
	for(int i = 0; i < 26; i++){
		count[i] = 0;
	}
	char s;
	scanf("%c", &s);
	while(((int)s >= (int)'a') && ((int)s <= (int)'z')){
		count[(int)s - (int)'a'] = count[(int)s - (int)'a'] + 1;
		scanf("%c", &s);
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < count[i]; j++){
		    char c = (char)(i + (int)'a');
			printf("%c", (char)(i + (int)'a'));
		}
	}
}