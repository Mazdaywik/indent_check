#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(char *s, int p[], int n) {
    int t = 0;
    p[0] = 0;
    for (int i = 1; i < n; i++) { 
        while((t > 0) && (s[t] != s[i])) {
            t = p[t - 1];
	}
	if (s[t] == s[i]) {
	    t++;
	}
	p[i] = t;
    }
}

int kmp(char pattern[], char *s) {
    int n = strlen(s), patlen = strlen(pattern);
    int p[patlen];
    int j = 0;
    prefix(pattern, p, patlen);

    for (int i = 0; i < n; i++) {
        while ((j > 0) && (pattern[j] != s[i])) j = p[j-1];
		
	if (pattern[j] == s[i]) j++;

    	if (j == 0) return 0;
		
	if (j == patlen) j = p[j-1];
    }
    return 1;
}

int main(int argc, char **argv) {
    char *pattern = argv[1], *s = argv[2];
    if (kmp(pattern, s)) printf("yes");
    else printf("no");
	
    return 0;
}