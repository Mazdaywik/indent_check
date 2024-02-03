#include <stdio.h>
#include <stdlib.h>

int check2(long long num){
    return num > 0 && (num & (num - 1)) == 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    long long result = 0, *sums = calloc(1<<n, sizeof(long long int ));
    int len = 0;
    for(int i = 0 ; i < n; i++){
        scanf("%lld", &sums[len++]);
        long long now = sums[len - 1];
        result += check2(sums[len - 1]);
        for(int j = len - 2; j >= 0; j--){
            sums[len++] = sums[j] + now;
            result += check2(sums[len - 1]);
        }
    }
    printf("%lld", result);
    free(sums);
}
