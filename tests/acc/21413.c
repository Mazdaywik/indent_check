#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>



int main() {
	long long int n, x, k,res,proiz_res,d_n;

	scanf("%lld%lld", &n, &x);
	
	n++;
	scanf("%lld", &k);
	res = k;
	d_n = n;
	proiz_res = k*(n-1);
	for (int i = 1; i < n - 1; ++i) {

		scanf("%lld", &k);

		res = res * x + k;
		proiz_res = proiz_res * x + (n - i - 1) * k;
	}
	scanf("%lld", &k);
	res *= x;
	res += k;
	printf("%lld ", res);
	printf("%lld", proiz_res);
}