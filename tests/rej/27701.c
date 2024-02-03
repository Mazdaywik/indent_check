#include <stdio.h>
#include <stdlib.h>



unsigned long *u;


int compare(unsigned long i, unsigned long j){
    if (u[i] < u[j]){
        return 1;
    }
    else if (u[i] == u[j]){
        return 0;
    }
    else{
    return -1;
    }
}

void swap(unsigned long i, unsigned long j){
    unsigned long h;
    h = u[i];
    u[i] = u[j];
    u[j] = h;
}


void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j))
                {
                    if (nel > 1){
                    int st = 1;
                    unsigned long long l = 0;
                    unsigned long long r = nel - 1;
                    while(st > 0){
                        st = 0;
                        for (unsigned long long i = l; i < r; i++){
                            if (compare(i, i+1) == 1){
                                swap(i, i+1);
                                st = 1;
                            }
                        }
                        for (unsigned long long i = r; i > l; i--){
                            if (compare(i, i-1) == -1){
                                swap(i, i-1);
                                st = 1;
                            }
                        }
                    }
                }}
                
int main(){
    int n;
    scanf("%d", &n);
    u = (unsigned long *)malloc(n * sizeof(unsigned long));
    for (int i = 0;  i < n; i++){
        scanf("%ld", &u[i]);
    }
    bubblesort(n, compare, swap);
    for (int i = 0;  i < n; i++){
        printf("%ld ", u[i]);
    }
}