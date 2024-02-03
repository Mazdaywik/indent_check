#include <stdio.h>
int main() 
{
    unsigned long long x;
    scanf("%llu", &x);
    unsigned long long int fib[1000];
    fib[0]=1;
    fib[1]=2;
    int i = 2;
    for (; fib[i-1]<=x && fib[i-2]<fib[i-1];i++)
    {
            fib[i]=fib[i-2]+fib[i-1];
    }
    for (i-=2;i>=0;i--)
    {
        if(x>=fib[i])
        {
            x-=fib[i];
            printf("1");
        }
        else
            printf("0");
    }
    return 0;
}