#include <stdio.h>

int main(void){
    long arr1[8], arr2[8], arr3[8];
    int found;

    for(int i = 0; i < 8; i++){
        scanf("%ld", &arr1[i]);
    }

    for(int i = 0; i < 8; i++){
        scanf("%ld", &arr2[i]);
    }

    for(int i = 0; i < 8; i++){
        arr3[i] = 0;
    }

    for(int i = 0; i < 8; i++){
        found = 0;
        for(int j = 0; j < 8; j++){
            if(arr1[i] == arr2[j] && arr3[j] == 0 && found == 0){
                arr3[j] = 1;
                found = 1;
            }
        }
    }

    int found_all = 1;
    for(int i = 0; i < 8; i++){
        if(arr3[i] == 0)
            found_all = 0;
    }

    if(found_all == 1)
        printf("yes");
    else
        printf("no");

    return 0;
}