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

void periodicpref(char *s) {
    int n = strlen(s);
    int p[n];
    prefix(s, p, n);
    for (int i = 1; i < n; i++) {
        if (p[i] > 0 && (i + 1) % (i + 1 - p[i]) == 0) {
            int k = (i + 1) / (i + 1 - p[i]);
            printf("%d %d\n", i + 1, k);
        }
    }
}

int main(int argc, char *argv[]) {
    char *s = argv[1];
    periodicpref(s);
}