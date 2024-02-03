#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	long long lena, a = 0, b = 0, bd, ad, k0 = 0, arra, arrb, lenb;
	scanf("%lld", &lena);
	for (long long i = 0; i < lena; i++)
	{
		scanf("%lld", &arra);
		a += pow(2, arra);
		if (arra == 0) k0++;
	}

	scanf("%lld", &lenb);
	for (long long i = 0; i < lenb; i++)
	{
		scanf("%lld", &arrb);
		b += pow(2, arrb);
		if (arrb == 0) k0++;
	}

	if (k0 == 2) printf("0 ");
	for (long long i = 1; i < 32; i++)
	{
		ad = a / pow(2, i);
		bd = b / pow(2, i);
		if ((ad % 2 == 1) && (bd % 2 == 1))
		{
			printf("%lld ", i);
		}
	}
}