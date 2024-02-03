#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void insertionsort(int *arr, int low, int high){
    for (int i = low + 1; i < high; i++){
        for (int j = i; j>low && abs(arr[j]) < abs(arr[j - 1]); j--)
            swap(&arr[j - 1], &arr[j]);
    }
}


void merge(int *arr, int low, int med, int high){
    int *s;
    s = (int*)malloc((high - low + 1)*sizeof(int));
    int i = low;
    int j = med;
    int h = 0;
    //for (int q = 0; q < high; q++){
    //    printf("%d arr ", arr[q]);
    //    printf("\n");
    //}
    while (h < high - low){
        if ((j <= high - 1) && ((i == med) || (abs(arr[j]) < abs(arr[i])))){
            s[h] = arr[j];
            //printf("%d %d %d %d %d %d jjjjjj \n",i,j, h, arr[i], arr[j], s[h]);
            j++;
        }
        else{
            s[h] = arr[i];
            //printf("%d %d %d %d %d %d  iiiii \n",i,j, h, arr[i], arr[j], s[h]);
            i++;
        }
        
        h++;
    }
    for (int i = low; i < high; i++){
        arr[i] = s[i - low];
        //printf("%d %d %d %d  aaaaa \n",i,low, high, arr[i]);
    }
    free(s);
}

void mergesort(int *arr, int low, int high){
    if (low >= high - 1) return;
    if ((high - low) < 5){
        //printf("ddddddddd \n");
        insertionsort(arr, low, high);
        return;
    }
    int med = floor((low + high) / 2);
    mergesort(arr, low, med);
    mergesort(arr, med, high);
    merge(arr, low, med, high);
    
}
//printf("ddddddddd");

int main(){
    int *s1;
    int n;
    scanf("%d", &n);
    s1 = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        scanf("%d", &s1[i]);
    }
    //fgets(s1, 1000, stdin);
    //s2 = (char*)malloc(sizeof(char) * 2500);
    mergesort(s1, 0, n);
    //int med = ((0 + n) / 2);
    //printf("%d aaaaa \n", med);
    //merge(s1, 0, med, n);
    //mergesort(s1, 0, n);
    for (int i = 0; i < n; i++)
        printf("%d ", s1[i]);
    free(s1);
    return 0;
}