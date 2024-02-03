#include <stdio.h>
#include <stdlib.h>

struct Task {
    int low, high;
};

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int* arr,int low,int high)
{
    int pivot=arr[high];//high - low) / 2 + low];
    int i=(low-1);

    for(int j=low;j<=high - 1;j++)
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


void quickSort(int* arr,int low,int high)
{
    if (low + 1 >= high) {
        return;
    }
    struct Task* stack = malloc(sizeof(struct Task)*high);
    int act_high = 1;
    stack[0].low = low;
    stack[0].high = high;
    while (act_high > 0) {
        act_high--;
        low = stack[act_high].low;
        high = stack[act_high].high;
        int pi = partition(arr,low,high);
        if (low < pi - 1) {
            stack[act_high].low = low;
            stack[act_high].high = pi - 1;
            act_high++;
        }
        if (pi + 1 < high) {
            stack[act_high].low = pi + 1;
            stack[act_high].high = high;
            act_high++;
        }
    }
    free(stack);
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n-1);

    for (int i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}