#include <stdio.h>
int main()
{
	unsigned long long a;
	unsigned long long b;
	unsigned long long m;
	scanf("%llu",&a);
	scanf("%llu",&b);
	scanf("%llu",&m);
	long long n = b;
	
	int dig[64] = {0};
	int i = 0;
	
	while (n>0) {
		dig[i] = n % 2;
		n = n / 2;
		i++;
	}
	
	unsigned long long ans = 0;
	for (int i = 0; i<64; i++) {
		ans = ((ans % m) * (2 % m)) % m;
		long remains = (dig[64-1-i]*a)%m;
		ans = (ans + remains)%m;
	}
	printf("%llu", ans);
	return 0;
}