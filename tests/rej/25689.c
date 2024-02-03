#include <stdio.h>
#include <stdlib.h>

void selectSort(int* arr, int n)
{
for (int i = 0; i < n; i++)
{
    int min=i;
    for (int j = i + 1; j < n; j++)
        if (arr[min] > arr[j])
            min=j;
    int t=arr[i];
	arr[i]=arr[min];
	arr[min] = t;
}
}

int swap(int* arr, int left, int right)
{
	int i=left, j=left;
	while (j<right)
	{
		if (arr[j] < arr[right])
		{
			int t=arr[j];
			arr[j]=arr[i];
			arr[i]=t;
			i++;
		}
		j++;
	}
	int t=arr[i];
	arr[i]=arr[right];
	arr[right]=t;
	return i;
}

void quickSortRec(int* arr, int left, int right, int m)
{
	if (right+1<m) 
	selectSort(arr, right+1);
	else
	{
		if (left<right)
		{
			int q=swap(arr, left, right);
			quickSortRec(arr, left, q-1, m);
			quickSortRec(arr,q+1,right,m);
		}
	}
}

void quickSort(int* arr, int n, int m)
{
	quickSortRec(arr, 0, n-1, m);
}


int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	int arr[n];
	for (int i=0; i<n; i++)
	scanf("%d", &arr[i]);
	quickSort(arr,n,m);
	for (int i=0; i<n; i++)
	printf("%d ", arr[i]);
	return 0;
}