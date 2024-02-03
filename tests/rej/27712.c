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


void shellsort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j))
                {
                    if (nel > 1){
                    unsigned long f1 = 1;
                    unsigned long f2 = 2;
                    unsigned long f;
                    unsigned long h = 2;
                    while (f2 <= nel){
                        h++;
                        f = f2;
                        f2 = f2 + f1;
                        f1 = f;
                    }
                    h--;
                    f = f1;
                    f1 = f2 - f1;
                    f2 = f;
                    while(h>0){
                        h--;
                        int d = f2;
                        f = f1;
                        f1 = f2 - f1;
                        f2 = f;
                        for (int g = 0; g<nel; g++){
                            for (int k = g-d; k>=0 && compare(k,k+d)==1;k-=d){
                                swap(k, k+d);
                                  }
                             }
                          }
                    }
                }
                
int main(){
    int n;
    scanf("%d", &n);
    u = (unsigned long *)malloc(n * sizeof(unsigned long));
    for (int i = 0;  i < n; i++){
        scanf("%ld", &u[i]);
    }
    shellsort(n, compare, swap);
    for (int i = 0;  i < n; i++){
        printf("%ld ", u[i]);
    }
}