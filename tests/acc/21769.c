#include <stdio.h>

int main(void){
    long long n;

    scanf("%lld", &n);

    long long arr[n], k;

    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    scanf("%lld", &k);

    long long sum = 0, res = -9223372036854775807;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(i >= k)
            sum -= arr[i - k];

        if(sum > res && i >= k - 1)
            res = sum;
    }

    printf("%lld", res);

    return 0;
}