#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void insertSort(int* arr, int n)
{
    int new_el, loc;
    for (int i=1; i<n; i++)
{
        new_el=arr[i];
        loc=i-1;
        while(loc >= 0 && abs(arr[loc]) > abs(new_el))
{
            arr[loc+1]=arr[loc];
            loc=loc-1;
}
        arr[loc+1] = new_el;
}
}

int comp(int a, int b)
{
    return (abs(a)-abs(b));
}

void merge(int* arr, int (*comp)(int a, int b), int k, int l, int m) 
{
    int t[m-k+1];
    int i=k, j=l+1, h;
    for(h=0; h<m-k+1; h++)
    {
        if (j<=m && (i==l+1 || (comp(arr[j], arr[i])<0)))
        {
            t[h]=arr[j];
            j++;
        }
        else
        {
            t[h]=arr[i];
            i++;
        }
    }
    for(h--; h>=0; h--) 
    arr[h+k]=t[h];
}

void merge_sort_rec(int* arr, int (*comp)(int a, int b), int low, int high){
    if (high-low<5)
        insertSort(arr+low, high-low+1);
    else 
    {
        int mid=(low+high)/2;
        merge_sort_rec(arr, comp, low, mid);
        merge_sort_rec(arr, comp, mid+1, high);
        merge(arr, comp, low, mid, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) 
    scanf("%d", arr+i);
    merge_sort_rec(arr, comp, 0, n-1);
    for(int i=0; i<n; i++) 
    printf("%d ", arr[i]);
    return 0;
}