#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Task {
    int low, high;
};

void quick_sort(int n, int *arr)
{
    struct Task stack[2 * n];
    int ind = 0;
    stack[ind].low = 0;
    stack[ind].high = n-1;
    while (ind >= 0)
    {
        struct Task x = stack[ind];
        ind--;
        int f = x.low, l = x.high;
        int i = f, j = f, elem;
        while (i < l)
        {
            if (arr[i] < arr[l])
            {
                elem = arr[j];
                arr[j] = arr[i];
                arr[i] = elem;

                j++;
            }
            i++;
        }
        elem = arr[j];
        arr[j] = arr[l];
        arr[l] = elem;
        int q = j;
        if (x.low < q-1)
        {
            ind++;
            stack[ind].low = x.low;
            stack[ind].high = q-1;
        }
        if (q+1 < x.high)
        {
            ind++;
            stack[ind].low = q+1;
            stack[ind].high = x.high;
        }
    }
}


int main(int argc, char ** argv) 
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quick_sort(n, arr);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}