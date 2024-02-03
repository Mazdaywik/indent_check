#include <stdio.h> 
#include <string.h>
int strdiff(char *a, char *b){
    int bits=0;
    for(int i=0; i < strlen(a) || i < strlen(b); i++){
        for(int mask=1; mask!=256; mask=mask << 1){
            if((a[i] & mask) != (b[i] & mask)){
                return bits;
            }
            bits++;
        }
    }
    return -1;
}