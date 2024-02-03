#include <stdio.h>

int main (int argc , char ** argv)
{
    unsigned long long a, b, m, new, last, ans;
    ans = 0;
    scanf("%lld%lld%lld", &a, &b, &m);
    int i;
    i = 0; 
    new = b;
    long long array[64];
    while (new > 0){
        array[i] = new % 2;
        new  = new >> 1; 
        i += 1;
    }
    for (int j = 0; j < i - 1; j++){
        ans = ((((ans % m) + (((a % m) * (array[i - j - 1] % m)) % m)) % m) * 2) % m;
    }
    ans = (ans + (((array[0] % m) * (a % m)) % m)) % m;
    printf("%lld\n", ans);
 return 0;
}