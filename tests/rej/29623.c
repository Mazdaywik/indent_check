#include <stdio.h>
unsigned long long fibonacci(unsigned long long n, int type)// 0 - index; 1 - number
{
    if (n == 0){
        if (type == 1)
            return n;
        else
            return 1;}
    else if (n == 1){
        if (type == 1)
            return n;
        else
            return 1;}

    unsigned long long f1 = 0;
    unsigned long long f2 = 1;
    unsigned long long f3 = 1;
    unsigned long long i = 0;
    while (f3 < n + 1)
    {
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
        i+=1;
    }
    if (type == 1)
        return f2;
    else
        return i;
}

void fibsys(long long n, long long ans[])
{
    while (n > 0){
        long long f = fibonacci(n, 1);
        ans[fibonacci(n,0)-1] = 1;
        n = n - f;
    }
}


int main(void)
{
    long long n;
    scanf("%lld", &n);
    
    long long LENGTH = fibonacci(n,0);
    long long ans[LENGTH];
    for(int i=0; i< LENGTH; i++)
        
        ans[i] = 0;
    fibsys(n,ans);
    for(long long i=LENGTH; i>0 ;i--){
        
        printf("%lld", ans[i-1]);}
    printf("\n");
    return 0;
}