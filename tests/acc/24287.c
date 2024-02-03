#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    double arr[n];
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d/%d", &a, &b);
        arr[i] = log(1.0 * a / b);
    }
    double ans = arr[0];
    int l = 0, r = 0;
    double summ = 0;
    int pref = -1;
    for (int i = 0; i < n; i++) {
        summ += arr[i];
        if (summ > ans) {
            ans = summ;
            l = pref + 1;
            r = i;
        }
        if (summ < 0) {
            summ = 0;
            pref = i;
        }
    }
    printf("%d %d\n", l, r);
    return 0;
}