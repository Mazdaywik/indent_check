#include <stdio.h>

int(main)(){
    int n;
    long long int max;
    scanf("%d",&n);
    long long a[n]; 
    for (int i=0;i<n;i=i+1){
        scanf("%lld",&a[i]);
        }
    int k;
    long long int sum = 0; 
    scanf("%d",&k);  
    for (int i=0;i<k;i=i+1){
        sum = sum + a[i];
    }
    max = sum;
    for (int i=0,m=k;m<n;i=i+1,m=m+1){
        sum = sum - a[i]+ a[m];
        if (sum > max){
            max = sum;
        }
    }
    printf("%lld",max);
    return 0;
}