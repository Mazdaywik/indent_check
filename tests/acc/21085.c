#include <stdio.h>

int main (int argc , char ** argv )
{
    int len1, len2, A, B, C;
    A = 0;
    B = 0;
    scanf("%d", &len1); 
    for (int i = 0; i < len1; i++){
        int el;
        scanf("%d", &el);
        A = A | (1 << el);
    }
    scanf("%d", &len2);
    for (int j = 0; j < len2; j++){
        int el;
        scanf("%d", &el);
        B = B | (1 << el);
    }
    C = A & B;
    for (int k = 0; k < 32; k++){
        if (((1 << k) & C) == (1 << k)){
            printf("%d ", k);
        }
    }
  return 0;
}
