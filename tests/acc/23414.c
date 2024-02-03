#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
	char *s = argv[1];
	char *t = argv[2];
	int lens = strlen(s);

	int p[lens];
	int y = 0;
	p[0] = 0;
	int i = 1;
	while (i < lens){
		while((y > 0) && (s[y] != s[i])){
			y = p[y - 1];
		}
		if (s[y] == s[i]){
			y = y + 1;
		}
		p[i] = y;
		i = i + 1;
	}
	int q = 0;
	int k = 0;
	int lent = strlen(t);
	while (k < lent){
		while ((q > 0) && (s[q] != t[k])){
			q = p[q - 1];
		}
		if(s[q] == t[k]){
			q = q + 1;
		}
		if(q == lens){
			printf("%d\n", (k - lens + 1));
		}
		k = k + 1;
	}
	return 0;
}