#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void prefix_function (int n, char *s, int *pi){pi[0]=0; for (size_t i=1;i<n;i++)
     {int j = pi[i-1];
        while ((j>0)&&(s[i]!=s[j]))
             j=pi[j-1];
        if (s[i]==s[j])
            j++;pi[i]=j;}}
void kmpsubst(char s[], char p[], int kostil)
{
	int i, j, N=strlen(s),res=-1, M=strlen(p);int d[M]; prefix_function(M, p, d);
	for(i = 0, j = 0; i < N; i++){while(j > 0 && p[j] != s[i]) j=d[j - 1];
		if(p[j]==s[i]) j++;
		if(j == M){res=i-j+1; break;} if (res>-1) break;}
		if (res>-1) {printf("%d ",res+kostil); kmpsubst(s+res+1, p, kostil+res+1);}
	return;}
int main(int argc, char **argv) {
    char *t = argv[1]; char *s = argv[2]; kmpsubst(s,t,0);}
