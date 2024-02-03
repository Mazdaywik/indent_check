#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int compare(const void *a, const void *b){
    int count_a = 0;
    int count_b = 0;
    int len_a = strlen(a);
    int len_b = strlen(b);
    for(int i = 0; i < len_a; i++){
        if(((char*)a)[i] == 'a') count_a += 1;
    }
    for(int i = 0; i < len_b; i++){
        if(((char*)b)[i] == 'a') count_b += 1;
    }
    return count_a - count_b;
}

void Heapify(int (*compare)(const void *a, const void *b), int i, int width, int n, void *base){
    int j = 0;
    while(true){
        int l = 2 * i + 1;
        int r = l + 1;
        j = i;
        if(l < n && compare(((char*)base + i * width), ((char*)base + l * width)) < 0){
            i = l;
        }
        if(r < n && compare(((char*)base + i * width), ((char*)base + r * width)) < 0){
            i = r;
        }
        if(i == j){
            break;
        }
        void *tmp = malloc(width);
        memcpy(tmp, ((char*)base + i * width), width);
        memcpy(((char*)base + i * width), ((char*)base + j * width), width);
        memcpy(((char*)base +  j * width), tmp, width);
        free(tmp);
    }
}

void BuildHeap(int (*compare)(const void *a, const void *b), int n, int width, void *base){
    int i = (int)floor(n / 2) - 1;
    while(i >= 0){
        Heapify(compare, i, width, n, base);
        i -= 1;
    }
}

void hsort(void *base, size_t nel, size_t width,
        int (*compare)(const void *a, const void *b)){
            BuildHeap(compare, nel, width, base);
            int i = nel - 1;
            while(i > 0){
                void *tmp = malloc(width);
                memcpy(tmp, ((char*)base), width);
                memcpy(((char*)base), ((char*)base + i * width), width);
                memcpy(((char*)base + i * width), tmp, width);
                free(tmp);
                Heapify(compare, 0, width, i, base);
                i -= 1;
            }
    }


int main(int args, char **argv){
    int n = 0;
    scanf("%d ", &n);
    char base[n][1000];
    for(int i = 0; i < n; i++){
        char a[1000];
        fgets(a, 1000, stdin);
        strcpy(base[i], a);
    }
    hsort(base, n, 1000, compare);
    for(int i = 0; i < n; i++){
        printf("%s", base[i]);
    }
    return 0;
}

