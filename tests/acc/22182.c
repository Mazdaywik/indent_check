#include <stdio.h>
int main ()
{
	long long n, k, s = 0;
	scanf("%lld", &n);
	long long arr[n];
	for (long long i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	scanf("%lld", &k);
	for (long long i = 0; i<k; i++) {
		s += arr[i];
	}
	long long j = 0, mx = s;
	for (long long idx = k; idx < n; idx++) {
		s = s + arr[idx] - arr[j];
		j++;
		if (s > mx) {
			mx = s;
		}
	}
	printf("%lld\n", mx);
}