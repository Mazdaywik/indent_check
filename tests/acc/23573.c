#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int countA(char *a){
    int res = 0;
    for(int i = 0 ; a[i] != '\0'; i++){
        res += (int)(a[i] == 'a');
    }
    return res;
}

int comp(const void *a, const void *b){
    return countA(*(char **)a) - countA(*(char **)b);
}


void *get(void *base, size_t ind, size_t width){
    return (uint8_t *)base + (ind - 1) * width;
}

void swap(void *base, int a, int b, size_t width){
    for(int i = 0 ; i < width ; i++){
        uint8_t temp = *((uint8_t *)base + i + (a - 1)*width);
        *((uint8_t *)base + i + (a - 1)*width) = *((uint8_t *)base + i + (b - 1)*width);
        *((uint8_t *)base + i + (b - 1)*width) = temp;
    }
}

void hsort(void *base, size_t nel, size_t width,
           int (*compare)(const void *a, const void *b))
{
    for(int i = nel; i >=1 ; i--){
        if(i * 2 <= nel){
            int p = i;
            while (1){
                if(p*2 + 1 <= nel){
                    if(compare(get(base, p*2 + 1, width), get(base, p * 2, width)) > 0 && compare(get(base, p*2 + 1, width), get(base, p, width)) > 0){
                        swap(base, p*2 + 1, p, width);
                        p = p*2 + 1;
                    }else{
                        if(compare(get(base, p*2, width), get(base, p, width)) > 0){
                            swap(base, p*2 , p, width);
                            p = p*2;
                        }else{
                            break;
                        }
                    }
                }else if(p * 2 <= nel){
                   if(compare(get(base, p*2, width), get(base, p, width)) > 0){
                        swap(base, p*2 , p, width);
                    }
                    break;
                }else
                    break;
            }
        }
    }
    for(int i = nel ; i >= 1; i--){
        swap(base, nel , 1, width);
        nel--;
        int p = 1;
        while (1){
            if(p*2 + 1 <= nel){
                if(compare(get(base, p*2 + 1, width), get(base, p * 2, width)) > 0 && compare(get(base, p*2 + 1, width), get(base, p, width)) > 0){
                    swap(base, p*2 + 1, p, width);
                    p = p*2 + 1;
                }else{
                    if(compare(get(base, p*2, width), get(base, p, width)) > 0){
                        swap(base, p*2 , p, width);
                        p = p*2;
                    }else{
                        break;
                    }
                }
            }else if(p * 2 <= nel){
                if(compare(get(base, p*2, width), get(base, p, width)) > 0){
                    swap(base, p*2 , p, width);
                }
                break;
            }else
                break;
        }
    }
}
int main(int argc, char** argv) {
    int n;
    char* N = calloc(1000, sizeof(char));
    fgets(N, 1000, stdin);
    n = strtol(N, &n, 10);
    char **mas = calloc(n, sizeof(char*));
    for(int i = 0 ; i < n ; i++){
        mas[i] = calloc(1000, sizeof(char));
        fgets(mas[i], 1000, stdin);
    }
    hsort((void *)mas, n, sizeof(char *), comp);
    for(int i = 0 ; i < n ; i++){
        printf("%s", mas[i]);
        free(mas[i]);
    }
    free(mas);
    free(N);
    return 0;
}
