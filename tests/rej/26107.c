#include <stdio.h>

int res=0;

void power2(int sum, int* arr, int n, int index)
{
    if((sum&(sum-1))==0&&sum>=1) 
    res++;
    if (index>=n-1)
    return;
    for (int i=index+1; i<n; i++)
        power2(sum+arr[i], arr, n, i);
}

int main() 
{
    int n;
    scanf("%d", &n);
    int arr[24];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        power2(arr[i], arr, n, i);
    }
    printf("%d", res);
    return 0;
}