#include <stdio.h>
#include <math.h>

int main(){
    int A = 0;
    int B = 0;
    int lenA, lenB;
    scanf("%d", &lenA);
    for (int i = 0; i < lenA; i++)
    {
        int a;
        scanf ("%d", &a);
        a = pow (2 , a);
        A = A | a;
    }
    scanf("%d", &lenB);
    for (int i = 0; i < lenB; i++)
    {
        int b;
        scanf ("%d", &b);
        b = pow (2 , b);
        B = B | b;
    }
    int intersection = A & B;
    for (int i = 0; i < 32; i++)
    {
        if (intersection & 1 == 1)
        {
            printf ("%d ",i);
        }
        intersection >>= 1;
    }
    
    return 0;
}