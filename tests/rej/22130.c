#include <stdio.h>
#include <math.h>
int main()
{
    long long int s,x,y,res1;
    long long int i,n,k;
    n = 91;
    long long int arr[n];
    //long long int res[n];
    //char res[] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'}; 
    long long int res[n];
    for (i=0;i<n;i++) res[i] = 0;
    //char res[91] = {0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000};
    x = 1;
    y = 2;
    arr[0] = 1;
    arr[1] = 2;
    for (i = 2; n > i; i++){
        arr[i] = x + y;
        x = y;
        y = arr[i];
    }
    scanf("%lld", &s);
    i = n - 1;
    res1 = 0;
    k = -1;
    //printf("Сумма: %Ld\n", s);
    while (i > -1){
        //printf("Сумvvvvма: %Ld %Ld %Ld \n", s, arr[i], i);
        
        if (arr[i] <= s){
            res[i] = 1;
            if (k == -1) k = i + 1;
            s = s - arr[i];
            i --;
        }
        i --;
    }
    //for (i = 0;i<n;i++) printf("%lld", res[i]);
    if (k == -1) printf("0");
    else{
    for (i = 0;i<k;i++){
    //    res1 = res1 + res[i] * pow(10, i);
        printf("%lld", res[k-i-1]);
    }
    }
    //res1 = atoll(res);
    //for (i = 0; i < n; i++)
    //printf("\n%lld ", res1);
    return 0;
}