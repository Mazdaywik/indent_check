#include <stdio.h>
int main(){
	long n, k;
	scanf("%ld", &n);
	long long a[n];
	for (int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	scanf("%ld", &k);
	long long sum = 0, msum = 0;
	for (int i = 0; i < k; i++){
		sum = sum + a[i];
	}
	msum = sum;
	for (int i = k; i < n; i++){
		sum = sum + a[i] - a[i - k];
		if (sum > msum){
			msum = sum;
		}
	}
	printf("%lld", msum);
	return 0;
}