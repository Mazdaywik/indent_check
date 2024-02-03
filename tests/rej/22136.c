#include <stdio.h> 
#include <math.h> 
 
int main() 
{ 
    unsigned long int s, i, n, a, b, m, s1, s2; 
    scanf("%lu", &a); 
    s1 = 0; 
    s2 = 0; 
    for (i=0;i < a; i++){ 
        scanf("%lu", &n); 
        s1 = s1|(1<<n); 
        } 
    scanf("%lu", &b); 
    for (i=0;i < b; i++){ 
        scanf("%lu", &m); 
        s2 = s2|(1<<m); 
    } 
    s = s1 & s2;
    for (i=0;i<32;i++) if ((s>>i) & 1 == 1)
    printf("%lu ", i); 
    return 0; 
}