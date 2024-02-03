#include <stdio.h>


unsigned long long int cash[10000] = { 0 };

unsigned long long int fibonacci(unsigned long long int n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    else{
        if(cash[n] != 0){
            return cash[n];
        }
        unsigned long long int a = (fibonacci(n-2) + fibonacci(n-1));
        cash[n] = a;
        return a;
    } 
}


int main(int args, char **argv){
    unsigned long long int n, f, nn = 0;
    int l = 0;
    scanf("%llu", &n);
    nn = n;
    for(unsigned long long int i = 1; i <= n; i++){
        unsigned long long int a = fibonacci(i);
        if(a <= n){
            l = i + 1;
        }
        else{
            break;
        }
    }
    char res[l];
    for(int i = 0; i < l; i ++){
        res[i] = 0;
    }
    while(n > 0){
        unsigned long long int f = 0;
        for(unsigned long long int i = 0; i <= n; i++){
            unsigned long long int a = fibonacci(i);
            //printf("%llu\n", a);
            if(a <= n){
                if(a == n){
                    if(i != 0){
                        res[l - i - 1] = '1';
                    }  
                }
                else{
                    if(i != 0){
                        res[l - i - 1] = '0';
                    }
                }
                f = a;
            }
            else{
                res[l - i] = '1';
                break;
            }
            
        }
        n -= f;
    }
    if(nn == 0){
        printf("0");
    }
    else{
        printf("%s", res);
    }
    return 0;
}