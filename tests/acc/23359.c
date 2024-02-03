#include <stdio.h>
#include <stdlib.h>

long long * arr;
void bubblesort(unsigned long nel,
	int(*compare)(unsigned long i, unsigned long j),
	void(*swap)(unsigned long i, unsigned long j))
{
	if ((nel == 1) || (nel == 0)) return;
	unsigned long left = 1;
	unsigned long right = nel - 1;
	while (left <= right)
	{
		for (unsigned long i = right; i >= left; i--)
			if (compare(i - 1, i) > 0) swap(i - 1, i);
		for (unsigned long i = left + 1; i <= right; i++)
			if (compare(i - 1, i) > 0) swap(i - 1, i);
		right--;
		left++;
	}
}

const unsigned long ARR_SZ = sizeof(arr) / sizeof(arr[0]);

int compare(unsigned long i, unsigned long j)
{
	if (arr[i] == arr[j])
	{
		return 0;
	}

	if (arr[i] < arr[j])
	{
		return -1;
	}

	return 1;
}

void swap(unsigned long i, unsigned long j)
{
	long long temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main()
{
	unsigned long n;
	scanf("%zu", &n);
	arr = (long long *) malloc(sizeof(long long) *n);
	for (unsigned long i = 0; i < n; i++)
	{
		scanf("%lld", arr + i);
	}

	bubblesort(n, compare, swap);
	for (unsigned long i = 0; i < n; i++)
	{
		printf("%lld ", arr[i]);
	}

	free(arr);
}