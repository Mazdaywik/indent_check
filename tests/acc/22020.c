#include <stdio.h>

int main (int argc, char **argv) {
    
    unsigned long long a, b, m;
    scanf("%llu %llu %llu", &a, &b, &m);

    int b_arr[64] = { 0 };
    int i = 0;
    while (b > 0) {
        b_arr[i] = b % 2;
        b = (b / 2);
        i++;
    }
    
    unsigned long long ost_gorner = ((a % m) * (b_arr[63] % m)) % m;
   
    
    for (int j = 62; j >= 0; j--) 
        ost_gorner = (((ost_gorner * (2 % m)) % m) % m + ((a % m) * b_arr[j]) % m) % m;
      
    
    printf("%llu", ost_gorner);
    return 0; 
    
}