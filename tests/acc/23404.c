#include <stdio.h>

int main (int argc , char ** argv )
{
    int a[8], b[8], are_arrays_equal;
    int max1;
    for (int i = 0; i < 8; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 8; i++){
        scanf("%d", &b[i]);
    }
    max1 = a[0];
    for (int i = 0; i < 8; i++){
        if (a[i] > max1){
            max1 = a[i];
        }

    }
    are_arrays_equal = 1;
    for (int i = 0; i < 8; i++){
        int exist = 0;
        for (int j = 0; j < 8; j++){
            if (b[i] == a[j] && b[j] <= max1) {
                a[j] = max1 + 1;
                exist = 1;
                break;
            }
        }
        if (exist == 0){
            are_arrays_equal = 0;
        }

    }
    if (are_arrays_equal == 0){
        printf("no");
    }
    else{
        printf("yes");
    }

  return 0;
}