#include<stdio.h>
#include<stdlib.h>
int main(){
    int len = 0, k = 0;
    scanf("%d", &len);
    int* arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++){
        scanf("%d", &k);
        arr[i] = k;
    }
    scanf("%d", &k);
    long sum = 0, i = 0, val = 0;
    while (i < k){
        sum += arr[i];
        i++;
    }
    val = sum;
    while (i < len){
        sum += arr[i] - arr[i - k];
        if (sum > val){
            val = sum;
        }
        i++;
    }
    printf("%ld", val);
    free(arr);
}