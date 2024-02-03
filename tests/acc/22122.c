#include <stdio.h>
int main (int argc , char ** argv ) {
	long long x,a,a1,p=0,pp=0;
	int n;
	a=0;
	scanf("%d%lld", &n, &x);
	for (int i=0; i<n+1; i++) {
		a1=a;
		scanf("%lld", &a);
		if (x==0) {
			p=a;
			pp=a1;
		}
		if (i!=n && x!=0) {
			p=(p+a)*x;
			if (i!=n-1)
				pp=(pp+a*(n-i))*x;
		}
		if (i==n-1)
			pp+=a;
		if (i==n && x!=0) {
			p+=a;
		}
	}
	printf("%lld %lld", p, pp);
	return 0;
}