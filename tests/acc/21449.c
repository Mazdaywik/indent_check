#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>

unsigned long long poly(int n, unsigned long long x, int* arr, unsigned long long a, unsigned long long m) {
	unsigned long long res = ((arr[n-1] % m) * (a % m)) % m;
	for (int i = n - 2; i > -1; --i) {
		res = (res % m) * 2;
		res=(res%m)+((a*arr[i])%m);
	}
	return res;
}

int main() {
	unsigned long long x, m,y,u;
	int n,i;
	scanf("%lld%lld%lld", &x, &y, &m);
	i = 0;
	if (y == 0) {
		n = 1;
	}
	else
	{
		n = 0;
	}
	u = y;
	while (u > 0){
		n += 1;
		u /= 2;
	}
	int arr[n];
	while (y > 0) {
		arr[i] = y % 2;
		y /= 2;
		i++;
	}
	printf("%lld", poly(n, 2, arr, x,m)%m);
	return 0;
}