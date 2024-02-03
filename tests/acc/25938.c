#include <stdio.h>
#define N 0.5

int permut() {
    double a[8], b[8];  // Объявляем массивы типа double
    for (int i = 0; i < 8; i++) {
        scanf("%lf", &a[i]);  // Считываем double-числа в массив a
    }
    for (int i = 0; i < 8; i++) {
        scanf("%lf", &b[i]);  // Считываем double-числа в массив b
    }
    for (int i = 0; i < 8; i++) {
        for (int k = 0; k < 8; k++) {
            if (a[i] == b[k]) {
                a[i] = N;
                b[k] = N;
                break;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        if (a[i] != N) return 0;
    }
    return 1;
}

int main(){
    int result = permut();
    if (result == 1) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}