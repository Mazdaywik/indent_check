#include<stdio.h>

int equal(int a[], int b[]){
    for (int i = 0; i < 8; i++){
        if (a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

// Heap's Algorithm
void permute(int k, int arr[], int arr2[], int* val){
    if (*val){
        return;
    }
    if (k == 1){
        *val = equal(arr, arr2);
    }
    else{
        permute(k-1, arr, arr2, val);
        for (int i = 0; i < k - 1; i++){
            if (!(k % 2)){
                int c = arr[i];
                arr[i] = arr[k-1];
                arr[k-1] = c;
            }
            else{
                int c = arr[0];
                arr[0] = arr[k-1];
                arr[k-1] = c;
            }
            permute(k-1, arr, arr2, val);
        }
    }
}

int main(){
    int a[8], b[8];
    for (int i = 0; i < 8; i++){
        scanf("%d", a + i);
    }
    for (int i = 0; i < 8; i++){
        scanf("%d", b + i);
    }
    int val = 0;
    permute(8, a, b, &val);
    if (val){
        printf("Yes");
    }
    else{
        printf("No");
    }
}