#include <stdio.h>

int isPow2(int sum){
    return (sum<=0)?(0):(!(sum & (sum - 1)));
}

int countPowRec(int* arr, int n, int sum, int ind){
    int c = isPow2(sum);
    for(int i = ind; i <=n; ++i){
        c += countPowRec(arr, n, sum + arr[i], i + 1);
    }

    return c;
}

int countPow(int* arr, int n){
    int count = 0;
    for(int i = 1; i <= n; ++i){
        count += countPowRec(arr, n, arr[i], i + 1);
    }
    
    return count;
}

int main(){
    int n, a, count=0;

    scanf("%d", &n);
    
    int arr[n+1];
    arr[0] = 0;

    for(int i = 1;i<=n;) scanf("%d", &arr[i++]);

    printf("%d", countPow(arr, n));
}