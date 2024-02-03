#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long a = 0;
	scanf("%lu", &a);
	
	unsigned long b = 0;
	scanf("%lu", &b);
	
	unsigned long m = 0;
	scanf("%lu", &m);
	
	a %= m;
	b %= m;
	
	int i = 63;
	unsigned long res = 0;
	unsigned long holder = 0;
	
	for (i = 63; i >= 0; i--)
	{
		res = b * ((a >> i) & 1) + (res * 2) % m;
		res %= m;
	}
	
	printf("%lu\n", res);
	return 0;
}