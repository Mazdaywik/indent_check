#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t width)
{
	void *temp = malloc(width);
	memcpy(temp, a, width);
	memcpy(a, b, width);
	memcpy(b, temp, width);
	free(temp);
}

void max_heapify(void *base, size_t nel, size_t width, int(*compare)(const void *a, const void *b), size_t i)
{
	size_t largest = i;
	size_t left = 2 *i + 1;
	size_t right = 2 *i + 2;

	if (left < nel && compare((char*) base + left *width, (char*) base + largest *width) > 0)
	{
		largest = left;
	}

	if (right < nel && compare((char*) base + right *width, (char*) base + largest *width) > 0)
	{
		largest = right;
	}

	if (largest != i)
	{
		swap((char*) base + i *width, (char*) base + largest *width, width);
		max_heapify(base, nel, width, compare, largest);
	}
}

void heapify(void *base, size_t nel, size_t width, int(*compare)(const void *a, const void *b))
{
	for (int i = (nel / 2) - 1; i >= 0; i--)
	{
		max_heapify(base, nel, width, compare, i);
	}
}

void hsort(void *base, size_t nel, size_t width, int(*compare)(const void *a, const void *b))
{
	heapify(base, nel, width, compare);
	for (int i = nel - 1; i >= 0; i--)
	{
		swap((char*) base, (char*) base + i *width, width);
		max_heapify(base, i, width, compare, 0);
	}
}

int compare(const void *a, const void *b)
{
	const char *str_a = *(const char **) a;
	const char *str_b = *(const char **) b;
	int count_a = 0, count_b = 0;
	for (int i = 0; str_a[i] != '\0'; i++)
	{
		if (str_a[i] == 'a')
		{
			count_a++;
		}
	}

	for (int i = 0; str_b[i] != '\0'; i++)
	{
		if (str_b[i] == 'a')
		{
			count_b++;
		}
	}

	return count_a - count_b;
}

int main()
{
	size_t nel;
	scanf("%zu", &nel);
	char **arr = malloc(sizeof(char*) *nel);
	for (int i = 0; i < nel; i++)
	{
		arr[i] = malloc(1000);
		scanf("%s", arr[i]);
	}

	hsort(arr, nel, sizeof(char*), compare);
	for (int i = 0; i < nel; i++)
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
	}

	free(arr);
	return 0;
}