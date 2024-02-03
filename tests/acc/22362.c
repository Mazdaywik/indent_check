#include <stdio.h>
#include <math.h>

int main() {
    long long len_A, len_B;
    long long A, B, k;
    long long ch_A = 0;
    long long ch_B = 0;
    scanf("%lld", &len_A);
    for (int i=0; i<len_A; i++){
        scanf(" %lld", &k);
        ch_A += pow(2, k);
    }
    scanf("%lld", &len_B);
    for (int i=0; i<len_B; i++){
        scanf(" %lld", &k);
        ch_B += pow(2, k);
    }
    int j = 0, s1, s2;
    if (ch_A % 2 == ch_B % 2 && ch_A % 2 == 1) {
        printf("%d", j);
    }
    j += 1;
    ch_A = ch_A / 2;
    ch_B = ch_B / 2;
    while (ch_A > 0 && ch_B > 0) {
        if (ch_A % 2 == ch_B % 2 && ch_A % 2 == 1) {
            printf(" %d", j);
        }
        ch_A = ch_A / 2;
        ch_B = ch_B / 2;
        j += 1;
    }
}