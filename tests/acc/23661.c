#include <stdio.h>

void selectionSort(int *num,int low,int high)
{
  int min, temp;
  for (int i = low; i < high; i++) 
  {
    min = i;
    for (int j = i + 1; j <= high; j++) 
    {
      if (num[j] < num[min]) 
        min = j;
    }
    temp = num[i];
    num[i] = num[min];
    num[min] = temp;
  }
}

void quicksort(int *arr, int first, int last,int m)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        if(last-first+1<m){
            selectionSort(arr,first,last);
        }
        pivot = last;
        i = first-1;
        for(int j=first;j<last;++j){
            if (arr[j]<=arr[pivot]){
                i++;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[pivot];
        arr[pivot]=arr[i+1];
        arr[i+1]=temp;
        quicksort(arr, first, i,m);
        quicksort(arr, i+2, last,m);
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int arr[n];
    for (int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1,m);
    for (int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
}