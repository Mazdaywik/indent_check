#include <stdio.h>
#include <stdlib.h>

struct Date
{
	int Day, Month, Year;
};

int getd(int key, struct Date date)
{
	if (key == 0) return date.Day;
	if (key == 1) return date.Month;
	return date.Year;
}

void datesort(int key, int lenarr, struct Date arr[lenarr])
{
	int count[10000];
	struct Date newarr[lenarr];
	for (int i = 0; i < 10000; i++) count[i] = 0;
	for (int j = 0; j < lenarr; j++)
	{
		int k = getd(key, arr[j]);
		count[k]++;
	}

	for (int i = 1; i < 10000; i++)
	{
		count[i] += count[i - 1];
	}

	for (int j = lenarr - 1; j >= 0; j--)
	{
		int k = getd(key, arr[j]);
		int i = count[k] - 1;
		count[k] = i;
		newarr[i] = arr[j];
	}

	for (int i = 0; i < lenarr; i++)
	{
		arr[i] = newarr[i];
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	struct Date darr[n];
	for (int i = 0; i < n; i++) scanf("%d %d %d", &darr[i].Year, &darr[i].Month, &darr[i].Day);
	for (int i = 0; i < 3; i++) datesort(i, n, darr);
	for (int i = 0; i < n; i++) printf("%04d %02d %02d\n", darr[i].Year, darr[i].Month, darr[i].Day);
}