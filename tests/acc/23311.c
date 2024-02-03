#include <stdio.h>
#include <stdlib.h>

long long maxel(int arr[8])
{
	long long ma = arr[0];
	for (int i = 0; i < 8; i++)
	{
		if (ma < arr[i])
		{
			ma = arr[i];
		}
	}

	return ma;
}

int max(long long a, long long b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	long long a1[8], a2[8], k = 0;
	for (int i = 0; i < 8; i++)
	{
		scanf("%lld", &a1[i]);
	}

	for (int i = 0; i < 8; i++)
	{
		scanf("%lld", &a2[i]);
	}

	long long m = max(maxel(a1), maxel(a2)) + 1;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (a1[i] == a2[j])
			{
				a1[i] = m;
				a2[j] = m;
				k++;
				break;
			}	//это не сортировка, здесь я "избавляюсь" от совпадающих элементов
		}
	}

	if (k == 8)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
}