#include <stdio.h>
#include <math.h>

int main(void){
    int power_A, power_B, n;
    long set_A = 0, set_B = 0, interset;

    scanf("%d", &power_A);

    for(int i = 0; i < power_A; i++){
        scanf("%d", &n);
        set_A = set_A | (long)pow(2, n);
    }

    scanf("%d", &power_B);

    for(int i = 0; i < power_B; i++){
        scanf("%d", &n);
        set_B = set_B | (long)pow(2, n);
    }

    interset = set_A & set_B;

    for(int i = 0; i <= 31; i++){
        if((interset & (long)pow(2, i)) != 0)
            printf("%d ", i);
    }
    return 0;
}