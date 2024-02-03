#include <stdio.h>

struct Task
{
	int low, high;
};

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int n)
{
	struct Task stack[n];
	int top = -1;

	stack[++top].low = 0;
	stack[top].high = n - 1;

	while (top >= 0)
	{
		int low = stack[top].low;
		int high = stack[top--].high;

		int pi = partition(arr, low, high);

		if (pi - 1 > low)
		{
			stack[++top].low = low;
			stack[top].high = pi - 1;
		}

		if (pi + 1 < high)
		{
			stack[++top].low = pi + 1;
			stack[top].high = high;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}

	quickSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}