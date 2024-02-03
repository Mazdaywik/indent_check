#include <stdio.h>

int in_array(int array[], int elem){
    for(int i = 0; i < 8; i ++){
        if(array[i] == elem){
            return 1;
        }
    }
    return 0;
}

int main(int args, char **argv){
    int a[8], b[8] = {0};
    for(int i = 0; i < 8; i ++){
        int elem;
        scanf("%i", &elem);
        a[i] = elem;
    }
    for(int i = 0; i < 8; i ++){
        int elem;
        scanf("%i", &elem);
        b[i] = elem;
    }
    int founded_idexes[8] = {9, 9, 9, 9, 9, 9, 9, 9};
    int f_index = 0;
    short founded = 0;
    for(int i = 0; i < 8; i++){
        int elem = a[i];
        for(int j = 0; j < 8; j++){
            if(b[j] == elem){
                if(in_array(founded_idexes, j) == 0){
                    founded_idexes[f_index] = j;
                    f_index++;
                    founded++;
                    break;
                }
            }
        }
    }
    if(founded == 8){
        printf("yes");
    }
    else{
        printf("no");
    }
    return 0;
}