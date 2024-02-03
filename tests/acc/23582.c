#include <stdio.h>
#include <stdlib.h>

int *newArray(int *array, int start, int end){
    int *new = calloc(end - start, sizeof(int));
    for(int i = start, k = 0 ; i < end; i++){
        new[k++] = array[i];
    }
    return new;
}

void insertionSort(int *array, int len){
    int new[5] = {0};
    int was[5] = {0};
    for(int i = 0; i < len; i++){
        int min = 10000000, indMin = i;
        for(int j = 0; j < len; j++){
            if(abs(array[j]) < abs(min) && was[j] == 0){
                indMin = j;
                min = array[j];
            }
        }
        was[indMin] = 1;
        new[i] = min;
    }
    for(int i = 0 ; i < len ; i++){
        array[i] = new[i];
    }
}

void merge(int *res, int *left, int *right, int lenLeft, int lenRight){
    int leftInd = 0, rightInd = 0, ind = 0;
    while (leftInd < lenLeft || rightInd < lenRight){
        if(leftInd == lenLeft){
            res[ind++] = right[rightInd++];
            continue;
        }
        if(rightInd == lenRight){
            res[ind++] = left[leftInd++];
            continue;
        }
        if(abs(left[leftInd]) <= abs(right[rightInd]))
            res[ind++] = left[leftInd++];
        else
            res[ind++] = right[rightInd++];
    }
    free(left);
    free(right);
}

void mergeSort(int* array, int len){
    if(len < 5)
        return insertionSort(array, len);
    int *left = newArray(array, 0, len/2);
    int *right = newArray(array, len/2, len);
    mergeSort(left, len/2);
    mergeSort(right, len - len/2);
    printf("\n");
    merge(array, left, right, len/2, len - len/2);
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    int *array = calloc(n, sizeof(int));
    for(int i = 0 ; i < n; i++){
        scanf("%d", &array[i]);
    }
    mergeSort(array, n);
    for(int i = 0 ; i < n ; i++)
        printf("%d ", array[i]);
    free(array);
    return 0;
}
