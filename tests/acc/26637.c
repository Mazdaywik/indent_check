#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	int a = 0, b = 0;
	scanf("%d", &a);
	scanf("%d", &b);
	
	int arr[a + b];
	
	for (int i = 0; i < a; i++)
		arr[i] = INT_MIN;
	
	for (int i = 0; i < b; i++)
		arr[a + i] = INT_MAX;
	
	int answer[3] = {0, 0, 0};
	
	for (int i_a = 0; i_a < a; i_a++)
	{
		for (int i_b = 0; i_b < b; i_b++)
		{
			
			int element = 0;
			scanf("%d", &element);
			
			if (arr[i_a] < element)
			{
				arr[i_a] = element;
				
				if (answer[1] == i_a) 
					answer[0] = 0;
			}
			
			if (arr[a + i_b] > element)
			{
				arr[a + i_b] = element;
				
				if (answer[2] == i_b) 
					answer[0] = 0;
			}
			
			if (arr[i_a] == element && arr[a + i_b] == element)
			{
				answer[0] = 1;
				answer[1] = i_a;
				answer[2] = i_b; 
			}
		}
	}
	
	if (answer[0] == 0)
	{
		printf("none");
		return 0;
	}
	
	printf("%d %d", answer[1], answer[2]);
	return 0;
}