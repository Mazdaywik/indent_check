#include <stdio.h>

int main() {
    int arr1[8], arr2[8];

    for (int i = 0; i < 8; i++)
        scanf("%d", &arr1[i]);


    for (int i = 0; i < 8; i++)
        scanf("%d", &arr2[i]);

    for (int i = 0; i < 8; i++) {
        for (int i1 = 0; i1 < 8; i1++) {
            for (int i2 = 0; i2 < 8; i2++) {
                for (int i3 = 0; i3 < 8; i3++) {
                    for (int i4 = 0; i4 < 8; i4++) {
                        for (int i5 = 0; i5 < 8; i5++) {
                            for (int i6 = 0; i6 < 8; i6++) {
                                for (int i7 = 0; i7 < 8; i7++) {
                                    int check[8] = {0};
                                    check[i] = 1;
                                    check[i1] = 1;
                                    check[i2] = 1;
                                    check[i3] = 1;
                                    check[i4] = 1;
                                    check[i5] = 1;
                                    check[i6] = 1;
                                    check[i7] = 1;
                                    if((check[0] +
                                       check[1] +
                                       check[2] +
                                       check[3] +
                                       check[4] +
                                       check[5] +
                                       check[6] +
                                       check[7])== 8){
                                        if(arr1[i] == arr2[0] &&
                                            arr1[i1] == arr2[1] &&
                                            arr1[i2] == arr2[2] &&
                                            arr1[i3] == arr2[3] &&
                                            arr1[i4] == arr2[4] &&
                                            arr1[i5] == arr2[5] &&
                                            arr1[i6] == arr2[6] &&
                                            arr1[i7] == arr2[7]){
                                            printf("yes\n");
                                            return 0;
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
    printf("no\n");
    return 0;
}