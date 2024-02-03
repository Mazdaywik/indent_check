#include <stdio.h>

int main(void){
    long long n, x_0;

    scanf("%lld %lld", &n, &x_0);

    long long arr[n + 1];
    for(int i = 0; i < n + 1; i++){
        scanf("%lld", &arr[i]);
    }

    long long result_1 = arr[0];
    for(int i = 1; i < n + 1; i++){
        result_1 = (result_1 * x_0) + arr[i];
    }

    long long arr_proizv[n];
    for(int i = 0; i < n; i++){
        arr_proizv[i] = arr[i] * (n - i);
    }

    long long result_2 = arr_proizv[0];
    for(int i = 1; i < n; i++){
        result_2 = (result_2 * x_0) + arr_proizv[i];
    }

    printf("%lld %lld", result_1, result_2);

    return 0; 
}