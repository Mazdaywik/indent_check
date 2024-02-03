#include<stdio.h>
#include<stdlib.h>
void insertionsort(int *arr, long size){
    for (int i = 1; i < size; i++){
        int j = i - 1, k = arr[i];
        while (j >= 0 && abs(arr[j]) > abs(k)){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
}
void mergesort(int *arr, long size){
    if (size <= 1){
        return;
    }
    if (size < 5){
        insertionsort(arr, size);
        return;
    }
    mergesort(arr, size/2);
    mergesort(arr + size/2, !(size % 2) ? (size/2) : (size/2 + 1));
    int* temp = (int*)malloc(size * sizeof(int));
    int i = 0, j = 0, k = size/2;
    while (j < size/2 && k < size){
        if (abs(arr[j]) > abs(arr[k])){
            temp[i] = arr[k];
            k++;
        }
        else {
            temp[i] = arr[j];
            j++;
        }
        i++;
    }
    while (j < size/2){
        temp[i] = arr[j];
        j++;
        i++;
    }
    while (k < size){
        temp[i] = arr[k];
        k++;
        i++;
    }
    for (int i = 0; i < size; i++){
        arr[i] = temp[i];
    }
    free(temp);
}
int main(){
    long n = 0;
    scanf("%ld", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", arr + i);
    }
    mergesort(arr, n);
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    free(arr);
}