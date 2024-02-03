#include <stdio.h>

int main()
{
	long long n, x0, i;
	long long an, a;
	long long p = 0, dp = 0;

	scanf("%lld %lld", &n, &x0);

	for (i = n; i >= 0; i--) {
		scanf("%lld", &an);
		p = p * x0 + an;
		if (i > 0) {
			a = an * i;
			dp = dp * x0 + a;
		}
	}

	printf("%lld %lld\n", p, dp);

	return 0;
}