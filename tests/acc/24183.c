#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union int32
{
	int x;
	unsigned char bytes[4];
};

int getrazr(union int32 a, int n)
{
	if (a.x > 0) return (int) a.bytes[n];
	if (a.x == 0) return 0;
	if (n == 0) return ((int) a.bytes[n]) - 256;
	return ((int) a.bytes[n]) - 255;
}

void rs(int key, int lenarr, union int32 arr[lenarr])
{
	int count[512];
	for (int i = 0; i < 512; i++) count[i] = 0;
	for (int j = 0; j < lenarr; j++)
	{
		int k = getrazr(arr[j], key) + 256;
		count[k]++;
	}

	for (int i = 1; i < 512; i++)
	{
		count[i] += count[i - 1];
	}

	union int32 narr[lenarr];
	for (int j = lenarr - 1; j >= 0; j--)
	{
		int k = getrazr(arr[j], key) + 256;
		int i = count[k] - 1;
		count[k] = i;
		narr[i] = arr[j];
	}

	for (int i = 0; i < lenarr; i++)
	{
		arr[i] = narr[i];
	}
}

int main()
{
	const int n;
	scanf("%d", &n);
	union int32 arr[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i].x);
		memmove(arr[i].bytes, &arr[i].x, sizeof(int));
	}

	for (int i = 0; i < 4; i++)
	{
		rs(i, n, arr);
	}

	for (int i = 0; i < n; i++) printf("%d ", arr[i].x);
}