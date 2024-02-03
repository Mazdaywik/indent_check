#include <stdio.h>

#define MAX(a, b) ((a > b) ? (a) : (b))

int main(){
    long long arr[1000000];
    long long len, elem, k;

    scanf("%lld", &len);
    for (long long i = 0; i < len; ++i){
        scanf("%lld", &elem);
        if (i == 0){
            arr[0] = elem;
        }
        else{
            arr[i] = arr[i - 1] + elem;
        }
    }

    scanf("%lld", &k);

    long long max_sum = arr[k - 1];

    for (long long i = k, j = 0; i < len; ++i, ++j){
        max_sum = MAX(max_sum, arr[i] - arr[j]);
    }
    printf("%lld", max_sum);
}