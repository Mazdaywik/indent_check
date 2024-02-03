#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int i = 0;
	unsigned int k = 0;
	
	unsigned int len1 = 0;
	scanf("%u", &len1);
	
	unsigned int a = 0;
	for (i = 0; i < len1; i++)
	{
		scanf("%u", &k);
		a += 1 << k;
	}
	
	unsigned int len2 = 0;
	scanf("%u", &len2);
	
	unsigned int b = 0;
	for (i = 0; i < len2; i++)
	{
		scanf("%u", &k);
		b += 1 << k;
	}
	
	unsigned int c = a & b;
	for (i = 0; i < 32; i++)
		if ((c >> i) & 1)
			printf("%u\n", i);
		
	return 0;
}