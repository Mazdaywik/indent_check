#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void revarray(void *base, size_t nel, size_t width)
{
    for (int i=0; i < nel/2; i++) {
        char dinmem[width];
        char *left = (char*)base + i*width;
        char *right = (char*)base + (nel - 1 -i) * width;
        memcpy(dinmem,left, width);
        memcpy(left, right, width);
        memcpy(right, dinmem, width);
    }
}

int main(int argc, char** argv)
{
    return 0;
}