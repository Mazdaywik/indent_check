#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main (int argc , char ** argv )
{
    int x, x2, max1, sqrt1;
    scanf("%d", &x);
    x2 = x;
    if ((x2 < 0) && (x2 != -2147483648)){
        x2 = -x;
    }
    if (x2 == -2147483648){
        x2 = 2;
    }
    sqrt1 = (int)(sqrt(x2)) + 1;
    int * a = (int *)calloc(sqrt1 + 1, sizeof(int));

    for (int i = 2; i < sqrt1; i++){
        a[i] = 1;
    }
    a[0] = 0;
    a[1] = 0;
    int i, j;
    i = 2;
    j = 0;

    while (i < sqrt1){
        if (a[i] != 0){
            j = i * i;
            while (j <= sqrt1){
                a[j] = 0;
                j += i;
            }
        }
        i += 1;
    }
    max1 = 0;
    for (int i = 0; i < sqrt1 + 1; i++){
        if (a[i] != 0){
            while (x2 % i == 0){
                max1 = i;
                x2 = x2 / i;
            }
        }
     }
    if (x2 > 1){
        max1 = x2;
    }
    printf("%d", max1);
    free(a);
    /* Я 4 часа пытался понять, что не так с кодом. 
    Оказалось, проблема в -2^31.  Дело в том что -(-2^31) = 2^31, но это число не принадлежет int!!!
    Я был в шоке, когда это заметил. Прошу для последующих поколений подкорректировать ограничения,
    чтобы люди не умирали
    */

  return 0;
}