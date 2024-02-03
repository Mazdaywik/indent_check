#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void selectsort(int n, int a[], int left, int right){
    int j = right;
    while (j > left){
        int k = j;
        int i = j - 1;
        while (i >= left){
            if (a[k] < a[i]){
                k = i;
            }
            i -= 1;
        }
        int change;
        change = a[k];
        a[k] = a[j];
        a[j] = change;
        j -= 1;
    }
}
int Partition(int low, int high, int a[]){
    int i = low;
    int j = low, p;
    while (j < high){
        if (a[j] < a[high]){
            p = a[i];
            a[i] = a[j];
            a[j] = p;
            i += 1; 
        }
        j += 1;
    }
    p = a[i];
    a[i] = a[high];
    a[high] = p;
    return i;
}
void quicksortrec(int low, int high, int a[], int m, int n){
    if ((high - low + 1 < m) && (low < high)){
        selectsort(n, a, low, high);
    }
    else{
        while (low < high){
            int q = Partition(low, high, a);
            if ((q - low - 1) > (high - q - 1)){
                quicksortrec(q + 1, high, a, m, n);
                high = q - 1;
            }
            else{
                quicksortrec(low, q - 1, a, m, n);
                low = q + 1;
            }
        }
    }
}
void quicksort(int n, int a[], int m){
    quicksortrec(0, n - 1, a, m, n);
}
int main(){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    quicksort(n, a, m);
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
   return 0;
}