#include <stdio.h>

int main() {
    int a[8], b[8];
    scanf("%d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7]);
    scanf("%d %d %d %d %d %d %d %d", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7]);
    int num[8] = {0};
    int check = 0;
    for (int i=0; i<8; i++) {
        for (int k=0; k<8; k++) {
            if ((a[i] == b[k]) && (num[k] == 0)) {
                num[k] += 1;
                check += 1;
                break;
            }
        }
    }
    if (check == 8) {
        printf("yes");
    }
    else {
        printf("no");
    }
    return 0;
}