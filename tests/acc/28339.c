#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int* arr, int n)  
{ 
    int i, j, j1; 
    for (i = 0; i < n; i++) 
    {
        int min = arr[i];
        for (j = i+1; j < n; j++) 
          if (arr[j] < min) {
            min = arr[j];
            j1 = j;
          } 
        if (min != arr[i]) {
          swap(&arr[j1], &arr[i]); 
        }
    } 
}
int partition(int* arr,int low,int high) 
{
  int pivot=arr[high];//high - low) / 2 + low];
  int i=(low-1);  

  for(int j=low;j<=high;j++)
  {
    if(arr[j]<pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i+1], &arr[high]);
  return (i+1);
}


void quickSort(int* arr,int low,int high, int m, int n)
{
  static int i = 0;
  i++;
  if(low<high)
  {

    if ((high - low > m) && ((int)log10(n) > i)){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1, m, n);
        quickSort(arr,pi,high, m, n);
    }
    else {
        selectionSort(&arr[low], high - low + 1);
    }
  }
  i--;
}



int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    if (n > 0) {
      quickSort(arr, 0, n-1, m, n); 
    }

    for (int i = 0; i<n; i++) {
       printf("%d ", arr[i]);
    }

    free(arr);
  return 0;
}