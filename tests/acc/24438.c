#include <stdio.h>

unsigned long long int fib(int n) {
    unsigned long long int m[2][2] = {{1, 1},
                                      {1, 0}};
    unsigned long long int t[2][2] = {{1, 0},
                                      {0, 1}};

    while (n > 0) {
        if (n % 2) {
            unsigned long long int a = t[0][0] * m[0][0] + t[0][1] * m[1][0];
            unsigned long long int b = t[0][0] * m[0][1] + t[0][1] * m[1][1];
            unsigned long long int c = t[1][0] * m[0][0] + t[1][1] * m[1][0];
            unsigned long long int d = t[1][0] * m[0][1] + t[1][1] * m[1][1];
            t[0][0] = a;
            t[0][1] = b;
            t[1][0] = c;
            t[1][1] = d;
        }
        unsigned long long int a = m[0][0] * m[0][0] + m[0][1] * m[1][0];
        unsigned long long int b = m[0][0] * m[0][1] + m[0][1] * m[1][1];
        unsigned long long int c = m[1][0] * m[0][0] + m[1][1] * m[1][0];
        unsigned long long int d = m[1][0] * m[0][1] + m[1][1] * m[1][1];
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
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
