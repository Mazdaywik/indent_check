#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void prefix_function (int n, char *s, int *pi){pi[0]=0; for (size_t i=1;i<n;i++)
     {int j = pi[i-1];
        while ((j>0)&&(s[i]!=s[j]))
             j=pi[j-1];
        if (s[i]==s[j])
            j++;pi[i]=j;}}
int kmpsubst(char s[], char p[]){int i,j,N=strlen(s), M=strlen(p);int d[N];prefix_function(N, s,d);
	for (int i=0, j=0; i<M; i++) {
		while (j>0&&s[j]!=p[i]) j=d[j-1];
		if (s[j] == p[i]) j++;
		if(j==0){if (i-N+3==0) return 0; return 1;}}
	return 0;
}
int main(int argc, char** argv){char* s=argv[1]; char* p=argv[2];
if (kmpsubst(s,p)==0) printf("yes");else printf("no");}