#include <stdio.h>
#include <stdlib.h>

void swap(int *array, int a, int b){
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void selection_sort(int *arr, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        int min_index = i;
        for (int j = i + 1; j <= end; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr, i, min_index);
        }
    }
}


void quicksort(int* array, int start, int end, int m){
    if(start>=end)
        return;
    if (end-start + 1 < m)
        return selection_sort(array, start, end);
    int mid = array[(start + end)/2];
    int left = start, right = end;
    while (left < right){
        while (array[left] < mid)
            left++;
        while (array[right] > mid)
            right--;
        if(left<=right){
            swap(array, left, right);
            left++;
            right--;
        }
    }
    quicksort(array, start, right, m);
    quicksort(array, left, end, m);
}

int main(int argc, char** argv) {
    int n, m;
    scanf("%d%d", &n, &m);
    int *array = calloc(n, sizeof(int));
    for(int i = 0 ; i < n; i++){
        scanf("%d", &array[i]);
    }
    quicksort(array, 0, n-1, m);
    for(int i = 0 ; i < n ; i++)
        printf("%d ", array[i]);
    free(array);
    return 0;
}
