#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *fibstr(int n){
	int sum=0;
	int numfib[n+1];
	numfib[0] = 0;
	for(int i=1; i<=n; i++){
		if(i==1) {
			numfib[1] = 1; 
			sum += 1;
			continue;
		}
		if(i==2) {
			numfib[2] = 1; 
			sum += 1;
			continue;
		}
		numfib[i] = numfib[i-1]+numfib[i-2];
		sum += numfib[i];
	}
	char *stfib = (char *)malloc(sum+1);
	stfib[0] = '0';
	int prefsum=1;
	for(int i=1; i<=n; i++){
		if(i==1) {
			stfib[1] = 'a';
			prefsum += 1;
			continue;
		}
		if(i==2) {
			stfib[2] = 'b';
			prefsum += 1;
			continue;
		}
		for(int j=0; j<numfib[i]; j++){
			stfib[prefsum] = stfib[prefsum-numfib[i]];
			prefsum += 1;
		}
	}
	int len = numfib[n];
	char *res = (char*)calloc(len+1, sizeof(char));
	for(int i=sum+1-len, k=0; i <= sum; i++, k++) res[k] = stfib[i];
	free(stfib);
	return res;
}


int main(int argc, char **argv)
{   
	int n;
	scanf("%d", &n);
	char *func;
	func = fibstr(n);
	printf("%s", func);
	free(func);
	return 0;
}