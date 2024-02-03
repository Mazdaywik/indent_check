#include <stdio.h>

int main(int argc, char **argv) {
    int elementFound = 1, a[8], b, equal = 1;

    for (int i = 0; i < 8; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 8; i++) {
        scanf("%d", &b);

        for (int j = 0; j < 8; j++) {
            if (b == a[j]) {
                a[j] = 1100101;
                elementFound = 1;
                break;
            }
            elementFound = 0;
        }

        if (elementFound == 0) {
            equal = 0;
        }
    }

    if (equal == 0) {
        printf("no");
    } else {
        printf("yes");
    }

    return 0;
}
