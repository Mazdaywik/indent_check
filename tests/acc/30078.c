#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void push_pyramid(long elem_len, long n, int i, int (*compare)(void *, void *),
        char* heap_init){
    if (2*i < n && 2*i + 1 < n){
        if (compare(heap_init + elem_len*(2*i - 1), heap_init + elem_len*(2*i)) >= 0 &&
            compare(heap_init + (2*i - 1)*elem_len, heap_init + (i - 1)*elem_len) > 0){
            char temp[elem_len];
            memcpy(temp, (heap_init + elem_len * (2*i - 1)), elem_len);
            memcpy((heap_init + elem_len * (2*i - 1)), (heap_init + elem_len * (i - 1)), elem_len);
            memcpy((heap_init + elem_len * (i - 1)), temp, elem_len);
            push_pyramid(elem_len, n, 2*i, compare, heap_init);
            push_pyramid(elem_len, n, i, compare, heap_init);
        }
        else if (compare(heap_init + elem_len*(2*i), heap_init + elem_len*(2*i - 1)) >= 0 &&
            compare(heap_init + elem_len*(2*i), heap_init + (i-1)*elem_len) > 0){
            char temp[elem_len];
            memcpy(temp, (heap_init + elem_len * (2*i)), elem_len);
            memcpy((heap_init + elem_len * (2*i)), (heap_init + elem_len * (i - 1)), elem_len);
            memcpy((heap_init + elem_len * (i - 1)), temp, elem_len);
            push_pyramid(elem_len, n, 2*i + 1, compare, heap_init);
            push_pyramid(elem_len, n, i, compare, heap_init);
        }
    }
    else if (2*i < n){
        if (compare(heap_init + elem_len*(2*i - 1), heap_init + elem_len*(i - 1)) > 0){
            char temp[elem_len];
            memcpy(temp, (heap_init + elem_len * (2*i - 1)), elem_len);
            memcpy((heap_init + elem_len * (2*i - 1)), (heap_init + elem_len * (i - 1)), elem_len);
            memcpy((heap_init + elem_len * (i - 1)), temp, elem_len);
            push_pyramid(elem_len, n, 2*i, compare, heap_init);
        }
    }
    else if (2*i + 1 < n){
        if (compare(heap_init + elem_len*(2*i), heap_init + elem_len*(i - 1)) > 0){
            char temp[elem_len];
            memcpy(temp, (heap_init + elem_len * (2*i)), elem_len);
            memcpy((heap_init + elem_len * (2*i)), (heap_init + elem_len * (i - 1)), elem_len);
            memcpy((heap_init + elem_len * (i - 1)), temp, elem_len);
            push_pyramid(elem_len, n, 2*i + 1, compare, heap_init);
        }
    }
}
void hsort(void *base2, long len, long elem_len, int (*compare)(void *, void *)){
    len++;
    for (int i = len; i > 0; i--){
        push_pyramid(elem_len, len, i, compare, (char*)base2);
    }
    while (len > 2){
        len--;
        char temp[elem_len];
        char *temp_arr = (char*)base2;
        memcpy(temp, (temp_arr + elem_len * (len - 1)), elem_len);
        memcpy((temp_arr + elem_len * (len - 1)), (temp_arr), elem_len);
        memcpy((temp_arr), temp, elem_len);
        push_pyramid(elem_len, len, 1, compare, (char*)base2);
    }
}


int comparestr(void *x, void *y){
    char *str1 = *((char**)x), *str2 = *((char**)y);
    int a1 = 0, a2 = 0;
    for (int i = 0; i < strlen(str1); i++){
        if (str1[i] == 'a'){
            a1++;
        }
    }
    for (int i = 0; i < strlen(str2); i++){
        if (str2[i] == 'a'){
            a2++;
        }
    }
    return a1 - a2;
}

int main(){
    char** pyramidka;
    pyramidka = (char **)calloc(2000, sizeof(char*));
    long n = 0;
    scanf("%ld", &n);
    for (int i = 0; i < n; i++){
        pyramidka[i] = (char*)calloc(500, sizeof(char));
        scanf("%s", pyramidka[i]);
    }
    hsort(pyramidka, n, sizeof(char*), comparestr);
    for (int i = 0; i < n; i++){
        printf("%s\n", pyramidka[i]);
    }
    for (int i = 0; i < n; i++){
        free(pyramidka[i]);
    }
    free(pyramidka);
}