#include <stdio.h>

int main() {
    long long n;
	long long x;
	scanf("%lld %lld", &n, &x);	
	long long a[n+1];
	long long b[n+1];
	
	for (int i=0; i<n+1; i++) {
		scanf("%lld", &a[i]);
		b[i] = a[i]*(n-i);
	}

	long long ans1 = a[0];
	long long ans2 = b[0];
	
	for (int i=1; i<n+1; i++) {
		ans1 = (ans1 * x) + a[i];
		if (i<n) {
			ans2 = (ans2 * x) + b[i];
		}
	}
	printf("%lld %lld", ans1, ans2);
    return 0;
}