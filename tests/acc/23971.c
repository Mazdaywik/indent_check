# include <stdio.h>

int main(){
    int n;
    unsigned long a, b, c;
    a = 0, b = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        unsigned long x;
        scanf("%ul", &x);
        a |= (1 << x);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        unsigned long x;
        scanf("%ul", &x);
        b |= (1 << x);
    }
    c = (a & b);
    for (int i = 0; i < 32; ++i) {
        unsigned long x = (1 << i) & c;
        if (x > 0){
            printf("%d ", i);
        }
    }
    return 0;
}