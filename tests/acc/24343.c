#include <stdio.h>
#include <stdlib.h>

int main()
{
	long n = 0;
	scanf("%ld", &n);
	
	long a0 = 0;
	scanf("%ld", &a0);
	
	long i = 0;
	
	long an[n+1];
	for (i = 0; i <= n; i++)
		scanf("%ld", &an[i]);
	
	long res1 = 0;
	for (i = 0; i < n; i++)
	{
		res1 += an[i];
		res1 *= a0;
	}
	
	res1 += an[n];
	
	long res2 = 0;
	for (i = 0; i < n-1; i++)
	{
		res2 += an[i] * (n-i);
		res2 *= a0;
	}
	
	res2 += an[n-1];
	
	printf("%ld %ld", res1, res2);
	
	return 0;
}