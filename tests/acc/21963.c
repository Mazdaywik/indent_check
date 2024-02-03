#include <stdio.h>

int main()
{
    unsigned long int s, i, n, a, b, m;
    unsigned long int res, res1;
    scanf("%lu", &a);
    scanf("%lu", &b);
    scanf("%lu", &m);
    n = 64;
    unsigned long int arr[n];
    for (i= 0; i < n; i++){
        arr[i] = 0;
    }
    i = 0;
    while (b > 0){
        arr[n - i - 1] = b % 2;
        if (b % 2 == 0){
             b = b / 2;
    //         printf("%lu\n", b);
        }
        else {b = (b - 1) / 2;}
        i++;
        
    }
    //for (i = 0; i <n; i++){
    //    printf("%lu", arr[i]);
    //}
    a = a % m;
    res = (a * arr[0]) % m;
    for (i = 1; i < n; i++)
        {
        res = ((res * 2) + (a * arr[i])) % m;
        //printf("%lu\n", res);
        }
      
    printf("%lu\n", res);
    return 0;
}