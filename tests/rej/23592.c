#include <stdio.h>
#include <math.h>

unsigned long long fyb(unsigned long long x)
{
    unsigned long long f0 = 1, f1 = 1, s, i = 1;
    if (x == 0 || x == 1)
        f1 = 1;
    else {while (i < x) {
        s = f1 + f0;
        f0 = f1;
        f1 = s;
        i = i + 1;
    }
        }
    return f1;
}

unsigned long long poisk(unsigned long long x)
{
    unsigned long long n, per = 0;
    for(n = 0; fyb(n) <= x; n++) {
        per = fyb(n);}
    return per;
}

unsigned long long which(unsigned long long x)
{
    unsigned long long n, per = 0;
    for(n = 1; fyb(n) <= x; n++) {
        per = fyb(n);}
    return (n - 1);
}

int main(int argc, char **argv)
{
    unsigned long long x, i, j, flag = 0;
    scanf("%lld", &x);
    unsigned long long arr[100], answer[100];
    for(j = 0; j < 100; j++) {
        arr[j] = 0;
        answer[j] = 0;}
    for(i = 0; x > 0; i++) {
        arr[i] = poisk(x);
        x = x - poisk(x);
    }
    for(i = 0; i < 100; i++) answer[100 - which(arr[i])] = 1;
    for(i = 0; i < 100; i++)
        if (answer[i] == 1) {
            flag = i;
            break;}
        else flag = flag + 1;
    if (flag == 100) printf("%d", 0);
    else {for(j = i; i < 100; i++) printf("%lld", answer[i]);}
    return 0;
}
