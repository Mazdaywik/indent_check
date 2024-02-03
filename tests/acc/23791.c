#include <stdio.h>

int main(int argc, char **argv)
{
    long n, k;
    scanf("%ld", &n);
    long long arr[n], i;
    for(i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
    scanf("%ld", &k);
    long long first_k = 0, max, sum;
    for(i = 0; i < k; i++)
        first_k += arr[i];
    max = first_k;
    sum = max;
    for(i = 0; i < n - k; i++){
        sum -= arr[i];
        sum += arr[k+i];
        if (sum >= max){
            max = sum;
        }
    }
    printf("%lld", max);
    return 0;
}
