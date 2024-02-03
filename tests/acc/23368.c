#include <stdio.h>
#include <string.h>
int main(int argc, char **argv){
	char *s = argv[1];
	int p[strlen(s)];
	int t = 0;
	p[0] = 0;
	int i = 1;
	int k;
	while (i < strlen(s)){
		while((t > 0) && (s[t] != s[i])){
			t = p[t - 1];
		}
		if (s[t] == s[i]){
			t = t + 1;
		}
		p[i] = t;
		k = i + 1;
		if((p[i] > 0) && ((k % (k - p[i])) == 0)){
			printf("%d %d\n", k, (k / (k - p[i])));
		}
		i = i + 1;
	}
	return 0;
}