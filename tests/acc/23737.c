#include <stdio.h>
#include <stdlib.h>
int main (int argc , char ** argv ) {
	long long int n,k,flag,sum=0,max=0;
	scanf("%lld", &n);
	long long int *a = (long long int*) malloc (n * sizeof(long long int ));
	for (int i=0; i<n; i++) scanf("%lld", &a[i]);
	scanf("%lld",&k);
	for (int i=0; i<k; i++) sum+=a[i];
		//printf("%d, %lld, %lld\n", i,a[i], sum);
	flag=a[0];
	max=sum;
	for (int i=1; i<n-k+1; i++) {
		sum-=flag;
		sum+=a[i+k-1];
		flag=a[i];
		//printf("%d, %lld, %lld, %lld, %lld\n",i,flag,a[i+k-1], sum, max);
		if (sum>max) max=sum;
	}
	printf("%lld", max);
	//for (int i=0; i<n; i++) free (a[i]);
	free(a);
	return 0;
}