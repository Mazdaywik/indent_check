#include <stdio.h>
#include <math.h>
int main() {
    unsigned long long int l;
    scanf("%llu", &l);
    int a=0;
    int b=1;
    unsigned long long int arr[10000];
    if (l == 0) {
        printf("0");
        return 0;
    }
    if (l == 1) {
        printf("1 ");
        return 0;
    }
    arr[0] = a+b;
    arr[1] = arr[0] + b;
    int n;
    for (n = 2; arr[n-1]<=l; n=n+1) {
        arr[n] = arr[n-1]+arr[n-2];
    }
    for (n=n-2;n>=0;n=n-1){
        if(l>=arr[n]){
            l=l-arr[n];
            printf("1");
        }
        else{
            printf("0");
        }
    }
    return 0;
}
