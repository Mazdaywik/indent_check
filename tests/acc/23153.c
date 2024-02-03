#include <stdio.h>
int main (int argc , char ** argv ) {
	long long arr[93]={0};
	long long x,n;
	scanf("%lld",&x);
	n=x;
	if (x==0) printf("%d",0);
	for (int i=0; i<=92; i++) {
		if (i==0 || i==1) arr[i]=1;
		else arr[i]=arr[i-2]+arr[i-1];
		//printf("%llu\n", arr[i]);
	}
	int i=91;
	while (x>=0 && i>0) {
		if (arr[i]<=x) {
			//printf("%lld, %lld, %d\n",x,arr[i],1);
			printf("%d", 1);
			x-=arr[i];	
		} else {
			if (arr[i]<n) {
				printf("%d", 0);
				//printf("%lld, %lld, %d\n",x,arr[i],0);
			}
		}
	i--;
	}
	return 0;
}