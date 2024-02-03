#include <stdio.h>

int main()
{
    unsigned long long a, b, m, sm = 0;
    scanf("%llu %llu %llu", &a, &b, &m);
   
    int b_bin[64] = {0};

    int k = 0;
    while (b > 0)
    {
        b_bin[k] = b % 2;
        b /= 2;
        k += 1;
    }
    
    for (int i = 63; i >= 0; i--)
    {
        sm = (((sm % m) * 2) % m) + (((a % m) * b_bin[i]) % m);
    }
    printf("%llu", sm % m);

    return 0;
}