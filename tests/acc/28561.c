#include <stdio.h>
#include <math.h>

int main() {
    long a[8];
    long b[8];
    long count1[8] = {0};
    long count2[8] = {0};

    for (int i = 0; i < 8; i++) {
        scanf("%ld", &a[i]);
    }

    for (int i = 0; i < 8; i++) {
        scanf("%ld", &b[i]);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i] == b[j]) {
                count1[i]++;
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i] == a[j]) {
                count2[i]++;
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        if (count1[i] != count2[i]) {
            printf("no");
            return 0;
        }
    }

    printf("yes");

    return 0;
}