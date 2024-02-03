#include <stdio.h>

int main() {
    int xs[8];
    int ys[8];
    int p = 0;
    for (int i = 0; i < 8; i++)
        scanf("%d", &xs[i]);
    for (int i = 0; i < 8; i++)
        scanf("%d", &ys[i]);
    for (int a0 = 0; a0 < 8; a0++) {
        for (int a1 = 0; a1 < 8; a1++) {
            if (a1 != a0) {
                for (int a2 = 0; a2 < 8; a2++) {
                    if ((a2 != a0) && (a2 != a1)) {
                        for (int a3 = 0; a3 < 8; a3++) {
                            if ((a3 != a0) && (a3 != a1) && (a3 != a2)) {
                                for (int a4 = 0; a4 < 8; a4++) {
                                    if ((a4 != a0) && (a4 != a1) && (a4 != a2) && (a4 != a3)) {
                                        for (int a5 = 0; a5 < 8; a5++) {
                                            if ((a5 != a0) && (a5 != a1) && (a5 != a2) && (a5 != a3) && (a5 != a4)) {
                                                for (int a6 = 0; a6 < 8; a6++) {
                                                    if ((a6 != a0) && (a6 != a1) && (a6 != a2) && (a6 != a3) && (a6 != a4) && (a6 != a5)) {
                                                        for (int a7 = 0; a7 < 8; a7++) {
                                                            if ((a7 != a0) && (a7 != a1) && (a7 != a2) && (a7 != a3) && (a7 != a4) && (a7 != a5) && (a7 != a6) 
                                                                && (xs[a0] == ys[0]) && (xs[a1] == ys[1]) && (xs[a2] == ys[2]) && (xs[a3] == ys[3]) 
                                                                && (xs[a4] == ys[4]) && (xs[a5] == ys[5]) && (xs[a6] == ys[6]) && (xs[a7] == ys[7])) {
                                                                p =1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (p == 1)
        printf("yes");
    else
        printf("no");
    return 0;
}