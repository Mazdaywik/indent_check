#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Merge(int k, int l, int m, int *arr){
    int _arr[m - k + 1];
    int i = k;
    int j = l + 1;
    int h = 0;
    while(h < m - k + 1){
        if(j <= m && (i == l + 1 || abs(arr[j]) < abs(arr[i]))){
            _arr[h] = arr[j];
            j += 1;
        }
        else{
            _arr[h] = arr[i];
            i += 1;
        }
        h += 1;
    }
    int ind = 0;
    for(int a = k; a <= m; a++){
        arr[a] = _arr[ind];
        ind += 1;
    }
}

void MergeSortRec(int low, int high, int n, int *arr){
    if(n < 5){
        int i = 1;
        while(i < n){
            int elem = arr[i];
            int loc = i - 1;
            while(loc >= 0 && (int)(abs(arr[loc])) > (int)(abs(elem))){
                arr[loc + 1] = arr[loc];
                loc -= 1;
            }
            arr[loc + 1] = elem;
            i += 1;
        }
    }
    else{
        if(low < high){
            int med = (int)((low + high) / 2);
            MergeSortRec(low, med, n, arr);
            MergeSortRec(med + 1, high, n, arr);
            Merge(low, med, high, arr);
        }
    }
}

int main(int args, char **argv){
    int n = 0;
    scanf("%d", &n);
    int *nums = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        int elem = 0;
        scanf("%d", &elem);
        nums[i] = elem;
    }
    MergeSortRec(0, n-1, n, nums);
    for(int i = 0; i < n; i++){
        printf("%i ", nums[i]);
    }
    free(nums);
    return 0;
}