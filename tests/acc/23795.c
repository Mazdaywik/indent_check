#include <stdio.h>
#include <stdlib.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

int convertInd(int byte, int indByte){
    if (indByte == 3){
        if(byte > 127)
            return byte - 128;
        return byte+128;
    }
    return byte;
}

void radixsort(union Int32 *array, int n){
    union Int32 arrayRes[n];
    for(int i = 0 ; i < 4; i++){
        int count[256] = {0};
        for(int j = 0; j < n ; j++){
            count[convertInd(array[j].bytes[i], i)]++;
        }
        int b1 = count[0];
        count[0] = 0;
        for(int j = 1; j < 256 ; j++){
            int t1 = b1;
            b1 = count[j];
            count[j] = count[j - 1] + t1;
        }
        for(int j = 0 ; j < n ; j++){
            arrayRes[count[convertInd(array[j].bytes[i], i)]++] = array[j];
        }
        for(int j = 0 ; j < n ; j++){
            array[j] = arrayRes[j];
        }
    }
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    union Int32 *array = calloc(n, sizeof(union Int32));
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &array[i].x);
    }
    radixsort(array, n);
    for(int i = 0 ; i < n ; i++){
        printf("%d ", array[i].x);
    }
    free(array);
    return 0;
}
