#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

long long * arr;
void shellsort(unsigned long nel,
	int(*compare)(unsigned long i, unsigned long j),
	void(*swap)(unsigned long i, unsigned long j))
{
	if (nel == 1) return;
	int a = 1, b = 1, lend = 0;
	while (b < nel)
	{
		int c = b;
		b += a;
		a = c;
		lend++;
	}

	int d[lend];
	int a1 = 1, b1 = 1;
	for (int i = 0; b1 < nel; i++)
	{
		int c1 = b1;
		b1 = a1 + b1;
		a1 = c1;
		d[i] = a1;
	}

	for (int i = lend - 1; i >= 0; i--)
	{
		for (int j = 0; j < nel; j++)
			for (int k = j - d[i]; k >= 0 && compare(k, k + d[i]) == 1; k -= d[i])
				swap(k, k + d[i]);
	}
}

const size_t lenarr = sizeof(arr) / sizeof(arr[0]);

int compare(unsigned long i, unsigned long j)
{
	if (arr[i] == arr[j]) return 0;
	if (arr[i] < arr[j]) return -1;
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
	for (int i = 0; i < n; i++) scanf("%lld", arr + i);
	shellsort(n, compare, swap);
	for (int i = 0; i < n; i++)
	{
		printf("%lld ", arr[i]);
	}

	free(arr);
}