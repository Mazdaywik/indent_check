#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

void revarray(void *base, size_t nel, size_t width)
{
    size_t i, j, k;
    for(i = 0, j = (nel - 1) * width; i < j; i += width, j -= width){
       for(k = 0; k < width; ++k){
            *(((char*)base)+i+k)^=*(((char*)base)+j+k);
            *(((char*)base)+j+k)^=*(((char*)base)+i+k);
            *(((char*)base)+i+k)^=*(((char*)base)+j+k);
       }
    }
}

int main()
{
    int n, i;
    printf("Введите размер массива: ");
    scanf("%i", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; ++i){
        printf("Введите элемент %i элемент: ", i);
        scanf("%i", &arr[i]);
    }
    for(i = 0; i < n; ++i){
        printf("%i ", arr[i]);
    }
    printf("\n");
    revarray(arr, n, sizeof(int));
    for(i = 0; i < n; ++i){
        printf("%i ", arr[i]);
    }
    printf("\n");
    return 0;
}