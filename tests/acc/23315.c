#include <stdio.h>

unsigned long binsearch(unsigned long nel, int(*compare)(unsigned long i))
{
	unsigned long a = 0, b = nel;
	while (b - a > 1)
	{
		unsigned long otr = (b - a) / 2, c = a + otr;
		if (compare(c) == 0)
		{
			return c;
		}

		if (compare(c) < 0)
		{
			a = c;
		}
		else
		{
			b = c;
		}
	}

	if (compare(a) == 0)
	{
		return a;
	}

	return nel;
}

int arr[5] = { 1, 2, 3, 8, 15 };

int x = 155;
int compar(unsigned long i)
{
	if (arr[i] < x)
	{
		return -1;
	}

	if (x == arr[i])
	{
		return 0;
	}

	return 1;
}

int main()
{
	printf("%lu\n", binsearch(5, compar));
}