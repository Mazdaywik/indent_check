#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

union Int32 
{ 
    int x; 
    unsigned char bytes[4]; 
};

int key(union Int32 *nums[], int c, int i)
{
	int Key = (*nums)[i].bytes[c];
	if (c == 3)
	Key ^= 128;
	return Key;
}

void dsort(union Int32 *arr, int c, int n, int base)
{
	int count[base];
	for(int i = 0; i < base; i++) 
	count[i] = 0;
	int j = 0;
	while (j < n)
	{
		int k = key(&arr,c,j);
		count[k]++;
		j++;
	}
	int i = 1;
	while (i < base)
	{
		count[i] += count[i - 1];
		i++;
	}
	union Int32 D[n];
	j = n-1;
	while (j >= 0)
	{
		int k = key(&arr, c, j);
		int i = count[k]-1;
		count[k] = i;
		D[i] = arr[j];
		j--;
	}

	for(int i = 0; i < n; i++)
	arr[i] = D[i];
}

void radixsort(union Int32 *arr, int n, int base)
{
	for(int i = 0; i < 4; i++)
	dsort(arr, i, n, base);
}


int main()
{
	int n;
	scanf("%i", &n);
	union Int32 nums[n];
	for(int i = 0; i < n; i++) 
	scanf("%i", &nums[i].x);
	radixsort(nums, n, 256);
	for(int i = 0; i < n; i++) 
	{
	if (i == n-1)	printf("%i\n", nums[i].x);
	else printf("%i ", nums[i].x);
	}
	return 0;
}