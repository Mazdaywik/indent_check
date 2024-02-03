#include <stdio.h>
#include <math.h>
int main()
{
    long long int s,x,y,res1;
    long long int i,n,k;
    n = 91;
    long long int arr[n];
    long long int res[n];
    for (i=0;i<n;i++) res[i] = 0;
    x = 1;
    y = 2;
    arr[0] = 1;
    arr[1] = 2;
    for (i = 2; n > i; i++){
        arr[i] = x + y;
        x = y;
        y = arr[i];
    }
    scanf("%lld", &s);
    i = n - 1;
    res1 = 0;
    k = -1;
    while (i > -1){
        if (arr[i] <= s){
            res[i] = 1;
            if (k == -1) k = i + 1;
            s = s - arr[i];
            i --;
        }
        i --;
    }
    if (k == -1) printf("0");
    else{
    for (i = 0;i<k;i++){
        printf("%lld", res[k-i-1]);
    }
    }
    return 0;
}