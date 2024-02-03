#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insertion_sort(int *arr, int left, int right)
{
	for (int i = left + 1; i < right; i++)
		for (int j = i; j > left && fabs(arr[j]) < fabs(arr[j - 1]); j--)
		{
			int a = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = a;
		}
}

void merge(int *arr, int left, int right, int sr)
{
	int t[right - left];
	int i = left, j = sr;
	for (int k = 0; k < right - left; k++)
	{
		if (j == right || i != sr && fabs(arr[j]) >= fabs(arr[i]))
		{
			t[k] = arr[i];
			i++;
		}
		else
		{
			t[k] = arr[j];
			j++;
		}
	}

	for (int i = left; i < right; i++) arr[i] = t[i - left];
}

void mergesortrec(int *arr, int le, int ri)
{
	if (ri - le < 2) return;
	if (ri - le < 5)
	{
		insertion_sort(arr, le, ri);
		return;
	}

	int sr = (le + ri) / 2;
	mergesortrec(arr, le, sr);
	mergesortrec(arr, sr, ri);
	merge(arr, le, ri, sr);
}

void mergesort(int *arr, int n)
{
	mergesortrec(arr, 0, n);
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	mergesort(arr, n);
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}