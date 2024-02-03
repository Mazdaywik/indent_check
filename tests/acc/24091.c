#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int Partition(int low, int high, int *arr){
    int i = low;
    int j = low;
    while(j < high){
        if(arr[j] < arr[high]){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i += 1;
        }
        j += 1;
    }
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void QuickSort(int low, int high, int n, int m, int *arr){
    if(n < m){
        int j = n - 1;
        while(j > 0){
            int k = j;
            int i = j - 1;
            while(i >= 0){
                if(arr[k] < arr[i]){
                    k = i;
                }
                i -= 1;
            }
            int temp = arr[j];
            arr[j] = arr[k];
            arr[k] = temp;
            j -= 1;
        }
    }
    else{
        while(low < high){
            int q = Partition(low, high, arr);
            if(q - low < high - q){
                QuickSort(low, q - 1, n, m, arr);
                low = q + 1;
            }
            else{
                QuickSort(q + 1, high, n, m, arr);
                high = q - 1;
            }
        }
    }
}


int main(int args, char **argv){
    int n, m = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    int *nums = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        int elem = 0;
        scanf("%d", &elem);
        nums[i] = elem;
    }
    QuickSort(0, n-1, n, m, nums);
    for(int i = 0; i < n; i++){
        printf("%i ", nums[i]);
    }
    free(nums);
    return 0;
}