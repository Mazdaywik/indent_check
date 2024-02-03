#include<stdio.h>
#include<stdlib.h>
long m = 0;
void switchsort(int *arr, long size){
    for (int i = 0; i < size - 1; i++){
        int min_i = i;
        for (int j = i + 1; j < size; j++){
            if (arr[min_i] > arr[j]){
                min_i = j;
            }
        }
        int t = arr[min_i];
        arr[min_i] = arr[i];
        arr[i] = t;
    }
}
void quicksort(int *arr, long size){
    if (size <= 1){
        return;
    }
    if (size < m){
        switchsort(arr, size);
        return;
    }
    int *temp = (int *)malloc(size * sizeof(int));
    int fst = arr[0], i_temp = 0;
    for (int i = 1; i < size; i++){
        if (arr[i] <= fst){
            temp[i_temp] = arr[i];
            i_temp++;
        }
    }
    quicksort(temp, i_temp);
    temp[i_temp] = fst;
    i_temp++;
    int j_temp = i_temp;
    for (int i = 1; i < size; i++){
        if (arr[i] > fst){
            temp[i_temp] = arr[i];
            i_temp++;
        }
    }
    quicksort(temp + j_temp, size - j_temp);
    for (int i = 0; i < size; i++){
        arr[i] = temp[i];
    }
    free(temp);
}
int main(){
    long n = 0;
    scanf("%ld %ld", &n, &m);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", arr + i);
    }
    quicksort(arr, n);
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    free(arr);
}