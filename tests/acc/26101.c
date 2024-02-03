#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void Kadane(int* num, int *denom, int n){
int l=0,r=0,
    start=0,i=0;
    float maxsum=log(num[0])-log(denom[0]),sum=0;
    while (i<n){
        sum+=log(num[i])-log(denom[i]);
        if (sum>maxsum){
            maxsum=sum;
            l=start;
            r=i;
        }
        i++;
        if (sum<0){
            sum=0;
            start=i;
        }
    }
    printf("%d %d",l,r);

}

int main(){
    int n;
    scanf("%d", &n);
    int numerator[n];
    int denominator[n];
    for(int i=0;i<n;++i){
        scanf("%d/%d",&numerator[i],&denominator[i]);
    }
    Kadane(numerator,denominator,n);
}