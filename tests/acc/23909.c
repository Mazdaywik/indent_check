#include <stdio.h>
#include <stdlib.h>

#define MINIMUM -1000000
#define MAXIMUM 1000000
#define MAX(x1, x2) (x1>x2)?(x1):(x2)
#define MIN(x1, x2) (x1>x2)?(x2):(x1)


int main(){
    int n, m, a, count = 0;
    scanf("%d %d", &n, &m);
    int *maxRow = (int*)malloc(n*sizeof(int));
    int *minCol = (int*)malloc(m*sizeof(int));

    for(int i = 0; i < n; ++i){
        maxRow[i]=MINIMUM;
    }

    for(int i = 0; i < m; ++i){
        minCol[i]=MAXIMUM;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%d", &a);
            maxRow[i] = MAX(maxRow[i], a);
            minCol[j] = MIN(minCol[j], a);
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if (maxRow[i] == minCol[j]){
                printf("%d %d ", i, j);
                count+=1;
            }
        }
    }

    if(count == 0){
        printf("none");
    }

    free(maxRow);
    free(minCol);

    return 0;
}