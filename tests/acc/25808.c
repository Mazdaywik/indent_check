#include <stdio.h>
#include <limits.h>

int main()
{
	int i = 0, len = 0;
	scanf("%d", &len);
	
	long int arr[len];
	for (i = 0; i < len; i++)
		scanf("%ld", &arr[i]);
	
	int k = 0;
	scanf("%d", &k);
	
	long long int sum = 0, maxsum = LONG_MIN;
	
	for (i = 0; i < len; i++)
	{
		sum += arr[i];
		
		if (i >= k)
			sum -= arr[i-k];
		
		maxsum = (i + 1 >= k) ? sum > maxsum ? sum : maxsum : maxsum;
	}
	
	printf("%lld", maxsum);
}