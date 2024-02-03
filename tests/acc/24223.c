#include <stdio.h>
#define max(a, b) if (b > a){ \
                        max = b;              \
                        l = start;            \
                        r = actual;           \
                    }

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    double nums[n];
    for(int i = 0 ; i < n ; i++){
        double a, b;
        scanf("%lf%c%lf", &a, &b, &b);
        nums[i] = a/b;
    }
    double max = nums[0], now;
    int l = 0, r = 0;
    for(int start = 0; start < n; start++){
        now = 1;
        for(int actual = start; actual < n; actual++){
            now *= nums[actual];
            max(max, now)
        }
    }
    printf("%d %d", l, r);
    return 0;
}


