#include <stdio.h>

void bubblesort(unsigned long nel,
				int (*compare)(unsigned long i, unsigned long j),
				void (*swap)(unsigned long i, unsigned long j))
{
	for (int i = 0; i < nel; ++i)
	{
		if (i % 2 == 0)
		{
			for (int j = i/2; j < nel - 1 - i/2; ++j)
			{
				if (compare(j, j + 1) == 1)
				{
					swap(j, j + 1);
				}
			}
		}
		else
		{
			for (int j = nel - 1 - i/2; j > i/2; --j)
			{
				if (compare(j - 1, j) == 1)
				{
					swap(j - 1, j);
				}
			}
		}
	}
}