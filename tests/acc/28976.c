#include <stdio.h>
void matrix_multiplication(unsigned long long int matrix1[2][2], unsigned long long int matrix2[2][2]) {
    unsigned long long int a = matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0];
    unsigned long long int b = matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1];
    unsigned long long int c = matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0];
    unsigned long long int d = matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1];
    matrix1[0][0] = a;
    matrix1[0][1] = b;
    matrix1[1][0] = c;
    matrix1[1][1] = d;
}

unsigned long long int fib(int n) {
    unsigned long long int m[2][2] = {{1, 1},
                                      {1, 0}};
    unsigned long long int t[2][2] = {{1, 0},
                                      {0, 1}};
    while (n > 0) {
        if (n % 2)
            matrix_multiplication(t, m);
        matrix_multiplication(m, m);
        n /= 2;
    }
    return t[0][0];
}


int main() {
    char mas[94] = {0};
    unsigned long long int x;
    scanf("%llu", &x);
    if (x == 0) {
        printf("%d", 0);
        return 0;
    }
    unsigned long long int s = 0;
    int j = 0;
    while (x > 0) {
        int i = 0;
        while (fib(i) <= x)
            i++;
        unsigned long long int f = fib(i - 1);
        s += f;
        x -= f;
        mas[i - 1] = '1';
        if (j < (i - 1))
            j = i - 1;
    }
    for (size_t a = j; a > 0; a--) {
        if (mas[a]=='1')
            printf("%d", 1);
        else
            printf("%d", 0);
    }
    return 0;
}