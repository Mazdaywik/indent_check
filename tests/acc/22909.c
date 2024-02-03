#include <stdio.h>
int main(int argc, char** argv)
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int max = 1<<n;
    unsigned long long res = 0;
    for(int curr=1; curr < max; curr++){
        int sum = 0;
        for(int j=0; j<n; j++){
            if((curr&(1<<j)) == (1<<j)) sum += a[j];
        }
        if(sum !=0 && (sum&(sum-1))==0) res++;
    }
    printf("%llu", res);
    return 0;
}