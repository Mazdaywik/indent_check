#include <stdio.h>

int main() {
    int array1[8];
    int array2[8];

    for (int i = 0; i < 8; i++) {
        scanf("%d", &array1[i]);
    }

    for (int i = 0; i < 8; i++) {
        scanf("%d", &array2[i]);
    }

    int used[8] = { 0 };

    for (int i = 0; i < 8; i++) {
        int found = 0;
        for (int j = 0; j < 8; j++) {
            if (!used[j] && array1[i] == array2[j]) {
                found = 1;
                used[j] = 1;
                break;
            }
        }
        if (!found) {
            printf("no\n");
            return 0;
        }
    }

    printf("yes\n");

    return 0;
}
