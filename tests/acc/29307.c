#include <stdio.h>

int main()
{
	long long int i, j, match, a, b, m;
	long long int s1[8], s2[8], s3[8];
	for (i = 0; i < 8; i++)
	{
		s1[i] = 0;
		s2[i] = 0;
		s3[i] = 0;
	}

	for (i = 0; i < 8; i++)
	{
		scanf("%lld", &a);
		s1[i] = a;
	}

	for (i = 0; i < 8; i++)
	{
		scanf("%lld", &b);
		s2[i] = b;
	}

	for (i = 0; i < 8; i++)
	{
		match = 0;
		for (j = 0; j < 8; j++)
		{
			if (s1[i] == s2[j] && s3[j] != 1)
			{
				s3[j] = 1;
				match = 1;
				break;
			}
		}

		if (match == 0)
		{
			printf("no");
			break;
		}
	}

	if (match != 0) printf("yes");
	return 0;
}