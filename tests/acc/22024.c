#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char* s)
{
	if (strlen(s) == 0) {
		return 0;
	}
	int res = 0,i=0;
	while (s[i] != '\0') {
		if (i != 0) {
			if (s[i] == ' ' && s[i - 1] != ' ') {
				res += 1;
			}
		}
		i++;
	}
	if (s[i - 1] != ' ') {
		res += 1;
	}
	return res;
}

int main(){
	char* stri = malloc(1000);
	gets(stri);
	printf("%d", wcount(stri));
	free(stri);
	return 0;
}