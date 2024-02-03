#include <stdio.h> 
#include <math.h> 
#include <stdint.h>

void revarray(void *base, size_t nel, size_t width)
{
    uint8_t *k = base;
    for (size_t i = 0; i < (nel / 2);i++){
        uint8_t *l = k + i*width;
        uint8_t *r = k + (nel - i - 1)*width;
        for (size_t j = 0; j < width; j++) {
            uint8_t temp = *l;
            *l = *r;
            *r = temp;
            l++;
            r++;
        }
    }
}



int main() {
    int s[] = {1, 2, 3, 4, 5, 6};
    revarray(s, 6, sizeof(int));
    for (size_t i = 0; i < 6; i++) {
        printf("%d ", s[i]);
    }
    return 0;
}