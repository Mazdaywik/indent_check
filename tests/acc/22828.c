#include <stdio.h>

int main(int argc, char **argv)
{
    long arr1[8], arr2[8], help[8] = {0};
    int i, count = 0, check, j;
    for (i = 0; i < 8; i++) scanf("%ld", &arr1[i]);
    for (i = 0; i < 8; i++) scanf("%ld", &arr2[i]);
    for (i = 0; i < 8; i++) {
        check = 0;
        for (j = 0; j < 8; j++) if ((arr1[i] == arr2[j]) && (help[j] == 0)) {
            check++;
            help[j] = 1;
            break;
        }
        if (check > 0) count++;
    }
    if (count == 8) {
        printf("yes");
    }
    else printf("no");
    return 0;
}