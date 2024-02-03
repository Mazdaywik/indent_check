#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main() {
	int n,m,k;
	long long int max_sum = 0, cur_sum = 0;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);

	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		max_sum += arr[i];
	}
	cur_sum = max_sum;
	for (int i = k; i < n; ++i) {
		cur_sum += arr[i] - arr[i - k];
		if (cur_sum > max_sum) {
			max_sum = cur_sum;
		}
	}
	printf("%lld", max_sum);
}