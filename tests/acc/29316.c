#include <stdio.h>

int main(int argc, char **argv)
{
    int A = 0, B = 0;
    int sizeA, sizeB;
    int a, b;
    
    scanf("%d", &sizeA);
    for (int i = 0; i < sizeA; ++i) {
        scanf("%d", &a);
        A = A | (1 << a);
    }
    
    scanf("%d", &sizeB);
    for (int i = 0; i < sizeB; ++i) {
        scanf("%d", &b);
        B = B | (1 << b);
    }
    
    for (int i = 0; i < 32; i++) {
        if ((A & B) == ((A & B) | (1 << i))) printf("%d ", i);
    }
    return 0;
}
