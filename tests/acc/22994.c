#include <stdio.h>
#include <stdlib.h>
void shellsort(int *arr, int low, int high)
{
    for (int i = low + 1; i <= high; ++i)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= low && abs(temp) < abs(arr[j]))
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = temp;
    }
}

void merge(int *arr, int low, int high)
{
    if (high - low + 1 < 5)
    {
        shellsort(arr, low,high);
    }
    else
    {
        int mid = (low + high) / 2;
        merge(arr, low, mid);
        merge(arr, mid + 1, high);

        int i = low, j = mid + 1, k = 0;
        int add_arr[high - low + 1];
        while (i <= mid && j <= high)
        {
            if (abs(arr[i])<=abs(arr[j])){
                add_arr[k]=arr[i];
                i++;
            }
            else
            {
                add_arr[k]=arr[j];
                j++;
            }
            k++;
        }
        while(i<=mid){
            add_arr[k]=arr[i];
            i++;
            k++;
        }
        while(j<=high){
            add_arr[k]=arr[j];
            j++;
            k++;
        }
        i=low,j=0;
        while(i<=high){
            arr[i]=add_arr[j];
            i++;
            j++;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    merge(arr,0,n-1);
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
    return 0;
}