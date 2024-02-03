#include <stdio.h>
#include <stdlib.h>
void revarray(void *base, size_t nel, size_t width)
{
    unsigned char *x = (unsigned char *)base;int j=nel-1;
    for(int i=0; i<j; i++)
    {for(int k=0; k<width; ++k){
            unsigned char tmp = *(x + i*width+k);
            *(x + i*width+k) = *(x + j*width+k);
            *(x + j*width+k) = tmp;
        }
        j--;
    }
}
int main()
{
    char array[10]="abc89defgh";
    revarray(array, 10, sizeof(char));
    for (int i=0; i<10; i++){printf("%c", array[i]);}
    return 0;
}
