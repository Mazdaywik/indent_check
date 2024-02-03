#include<stdio.h>
#include<stddef.h>
#include<string.h>
#include<stdlib.h>
int maxarray(void* arr, size_t size, size_t elem_t, int (compare)(void*, void*)){
    char *arr2 = (char*)arr;
    int i = 0;
    for (int j = 1; j < size; j++){
        if (compare(arr2 + i*elem_t, arr2 + j*elem_t) < 0){
            i = j;
        }
    }
    return i;
}