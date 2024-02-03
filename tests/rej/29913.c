#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date
{
	int Year, Month, Day;
};

void distributionsort(int base, struct Date *dates, int n, int IDX)
{
	int count[base];

	for (int i = 0; i < base; i++) count[i] = 0;
	
	for (int i = 0; i < n; i++)
	{
        int k;

        switch (IDX) {
            case 0: k = dates[i].Day - 1; break;
            case 1: k = dates[i].Month - 1; break;
            case 2: k = dates[i].Year - 1970; break;
            default: k = 0; 
        }
		
		count[k]++;
	}

	for (int i = 1; i < base; i++)
		count[i] += count[i - 1];

	struct Date sorted_dates[n];

	for (int i = n - 1; i >= 0; i--)
	{
        int k;

        switch (IDX) {
            case 0: k = dates[i].Day - 1; break;
            case 1: k = dates[i].Month - 1; break;
            case 2: k = dates[i].Year - 1970; break;
        }

		int j = --count[k];
		sorted_dates[j] = dates[i];
	}

	for (int i = 0; i < n; i++) 
		dates[i] = sorted_dates[i];
}

int main()
{
	int n;
	
	scanf("%d", &n);

	struct Date dates[n];

	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);

	int bases[] = {31, 12, 61}; 
	for (int i = 0; i < 3; i++)
		distributionsort(bases[i], dates, n, i);

	for (int i = 0; i < n; i++)
		printf("%02d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);

	return 0;
}