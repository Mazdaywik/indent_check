#include <stdio.h>

int main(){
    long arr1[8], num, sw;

    for(int i = 0; i<8;++i){
        scanf("%ld", arr1+i);
    }

    for(int i = 0; i<8;++i){
        scanf("%ld", &num);
        for(int j = i; j<8;++j){
            if(arr1[j] == num){
                sw = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = sw;
                break;
            }
            if(j == 7){
                printf("no");
                return 0;
            }
        }
    }
    printf("yes");
    return 0;
}