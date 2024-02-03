#include<stddef.h>
#include<string.h>
#include<stdlib.h>
void revarray(void *arr, size_t size, size_t elem_t){
    char *arr2 = (char*)arr;
    void *temp = malloc(elem_t);
    for (int i = 0; i < size / 2; i++){
        memcpy(temp, arr2 + i*elem_t, elem_t);
        memcpy(arr2 + i*elem_t, arr2 + (size - 1 - i)*elem_t, elem_t);
        memcpy(arr2 + (size - 1 - i)*elem_t, temp, elem_t);
    }
    free(temp);
}