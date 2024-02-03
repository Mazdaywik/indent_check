#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void prefix(char *s)
{
	int len = strlen(s), *a = (int*)calloc(len, sizeof(int));
	for(int i=0; i<len; i++) a[i] = 0;
	int t=0;
	a[0] = t;
	for(int i=1; i<len; i++){
        	while(t>0 && s[t] != s[i]) t = a[t-1];
        	if(s[t] == s[i]) t += 1;
		a[i] = t;
	}    
	for (int i = 2; i <= len; i++) {
		t = a[i - 1];
		while (t >= i / 2) {
			if (i % (i - t) == 0) {
				printf("%d %d\n", i, i / (i - t));
                		break;
			}
			if (t == i / 2) break;
			t = a[t - 1];
		}
	}
	free(a);
}

int main(int argc, char** argv)
{
	char *s;
	s = argv[1];
	prefix(s);
	return 0;
}