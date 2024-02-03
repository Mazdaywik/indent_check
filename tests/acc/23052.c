#include <stdio.h>
#include <math.h>

int main(){
    long count_a, count_b, number, a=0, b=0, ind=0;

    scanf("%ld", &count_a);
    for(int i=0;i<count_a; ++i){
        scanf("%ld", &number);
        if(((long)pow(2, number)&a) == 0){
            a+=(long)pow(2, number);
        }
    }

    scanf("%ld", &count_b);
    for(int i=0;i<count_b; ++i){
        scanf("%ld", &number);
        if(((long)pow(2, number)&b) == 0){
            b+=(long)pow(2, number);
        }
    }
    
    a&=b;
    while(a!=0){
        if(a%2==1){
            printf("%ld ", ind);
        }
        a/=2;
        ind++;
    }
    return 0;
}