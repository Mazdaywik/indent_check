#include <stdio.h>

int main(){
    long number, flag = 0;
    long fib_arr[91]={1, 2, 0};

    scanf("%ld", &number);

    if(number==0){
        printf("0");
    }

    for(long i=2;i<=90;++i){
        fib_arr[i] = fib_arr[i-1]+fib_arr[i-2];
    }
    for(long i = 90;i>=0;--i){
        if(flag == 1){
            if (number >= fib_arr[i]){
                number -= fib_arr[i];
                if (i == 0){
                    printf("1");
                }
                else{
                    printf("10");
                }
                --i;
            }
            else{
                printf("0");
            }
        }
        else{
            if(number >= fib_arr[i]){
                flag = 1;
                if (i == 0){
                    printf("1");
                }
                else{
                    printf("10");
                }
                number -= fib_arr[i];
                --i;
            }
        }
    }
    
    return 0;
}