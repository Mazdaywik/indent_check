#include <stdio.h>

int main() {
    int i, j, strcount, stolbcount, foundMatch = 0;
    scanf("%d%d", &strcount, &stolbcount);

    int coord[strcount][2], n = 0;
    long long a, maxstr[strcount][2], minstolb[stolbcount][2];

    for (i = 0; i < strcount; i++) {
        for (j = 0; j < stolbcount; j++) {
            scanf("%lld", &a);

            if (j == 0) {
                maxstr[i][0] = a;
                maxstr[i][1] = 0;
            }

            if (i == 0) {
                minstolb[j][0] = a;
                minstolb[j][1] = 0;
            }

            if (a > maxstr[i][0]) {
                maxstr[i][0] = a;
                maxstr[i][1] = j;
            }

            if (a < minstolb[j][0]) {
                minstolb[j][0] = a;
                minstolb[j][1] = i;
            }

            if (maxstr[i][0] == minstolb[j][0]) {
                coord[n][0] = i;
                coord[n][1] = j;
                n++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (maxstr[coord[i][0]][0] == minstolb[coord[i][1]][0]) {
            printf("%lld %lld", minstolb[coord[i][1]][1], maxstr[coord[i][0]][1]);
            foundMatch = 1;
        }
    }

    if (foundMatch == 0)
        printf("none");

    return 0;
}
