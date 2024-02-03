#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    unsigned long long a, b, m, i, j, sum;
    unsigned long long arr[1000];
    scanf("%lld %lld %lld", &a, &b, &m);
    for(i = 1; i < 1001; i++) {
        arr[1000 - i] = b%2;
        b = b / 2;
    }
    sum = (arr[0] * a) % m;
    for(j = 1; j < 1000; j++) {
        sum = (((sum%m)*2)%m + (a*arr[j])%m)%m;
    }
    printf("%lld \n", sum);
    return 0;
}