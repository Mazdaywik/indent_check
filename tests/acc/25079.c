#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


void selectsort(int *arr, int low, int high){
    int *s;
    s = (int*)malloc(1*sizeof(int));
    int j = high;
    while (j > low){
        int k = j;
        int i = j - 1;
        while (i >= low){
            if (arr[k] < arr[i]){
                k = i;
            }
            i--;
        }
        s[0] = arr[j];
        arr[j] = arr[k];
        arr[k] = s[0];
        j--;
    }
    //for (int i = low; i < high; i++){
    //    arr[i] = s[i - low];
    //}
    free(s);
}


int partition(int *arr, int low, int high) {
    int *s;
    s = (int*)malloc(sizeof(int) * (high - low));
    int i = low;
    int j = low;
    while (j < high){
        if (arr[j] < arr[high]){
            s[0] = arr[i];
            arr[i] = arr[j];
            arr[j] = s[0];
            i++;
        }
        j++;
        //for (int q = 0; q < high; q++)
        //    printf("%d ", arr[q]);
        //printf("\n");
        //printf("%d %d %d %d %d %d  iiiii \n",i,j, high, arr[i], arr[j], s[0]);
    }
    s[0] = arr[i];
    arr[i] = arr[high];
    arr[high] = s[0];
    free(s);
    return i;
}


void quicksortrec(int *arr, int low, int high, int m){
    if ((high - low + 1) < m){
        //printf("ddddddddd \n");
        selectsort(arr, low, high);
        return;
    }
    else{
        if (low < high){
            //for (int i = 0; i < high; i++){
            //    printf("%d ", arr[i]);
            //}
            //printf("aaaaaaaaaaa \n");
            int q = partition(arr, low, high);
            quicksortrec(arr, low, q-1, m);
            quicksortrec(arr, q+1, high, m);
        }
    }
    
}


void quicksort(int *arr, int n, int m){
    quicksortrec(arr, 0, n - 1, m);
}
//printf("ddddddddd");

int main(){
    int *s1;
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);
    s1 = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        scanf("%d", &s1[i]);
    }
    quicksort(s1, n, m);
    for (int i = 0; i < n; i++)
        printf("%d ", s1[i]);
    free(s1);
    return 0;
}