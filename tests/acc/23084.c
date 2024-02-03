#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rec_sum(long long *arr, size_t len, int index, long long sum, int *ans){

    sum += arr[index];  

    if(sum > 0 && ((sum & (sum - 1)) == 0))
        *ans += 1;

//    printf("%lld ", sum);

    for(int j = index + 1; j < len; j++){
        rec_sum(arr, len, j, sum, ans);
    }
}


int main(void){
    int n, ans = 0;
    scanf("%d", &n);

    long long arr[n];
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    for(int index = 0; index < n; index++){
        rec_sum(arr, n, index, 0, &ans);
//        printf("\n");
    }
    printf("%d", ans);
    return 0;
}