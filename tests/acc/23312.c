#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int str[10][2], stolb[10][2], a, b;
	scanf("%d%d", &a, &b);
	for (int i = 0; i < 10; i++)
	{
		str[i][0] = (-1) *pow(2, 30);
		stolb[i][0] = pow(2, 30);
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			int el;
			scanf("%d", &el);
			if (str[i][0] < el)
			{
				str[i][0] = el;
				str[i][1] = j;
			}

			if (stolb[j][0] > el)
			{
				stolb[j][0] = el;
				stolb[j][1] = i;
			}
		}
	}

	int arr1[10][2], arr2[10][2], k = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if ((i == stolb[j][1]) && (j == str[i][1]))
			{
				k++;
				printf("%d %d", i, j);
			}

			if (k == 1)
			{
				break;
			}
		}

		if (k == 1)
		{
			break;
		}
	}

	if (k == 0)
	{
		printf("None");
	}
}