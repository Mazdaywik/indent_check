#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n,k,s=0;
    scanf("%lld", &n);
    long long arr[n];
    for (long long i=0; i<n; i++){
        scanf("%lld", &arr[i]);
    }
    scanf("%lld", &k);
    for (long long i=0; i<k; i++){
        s+=arr[i];
    }
    long long ms=s;
    for (long long i=k; i<n; i++){
        s=s-arr[i-k]+arr[i];
        if (s>ms){ms=s;}
    }
    printf("%lld", ms);
}//на 27б из ЕГЭ похоже
