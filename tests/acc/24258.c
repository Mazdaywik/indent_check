#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

bool IsSaddlePoint(int** arr, int n, int imax, int jmax){ // Проверка по столбцу
    int i, j;
    int min = arr[imax][jmax];
    for(i = 0; i < n; ++i){
        if(min >= arr[i][jmax] && i != imax) return false;
    }
    return true;
}

int main()
{
    int n, m, i, j;
    int count_saddle = 0; // Количество седловых точек
    scanf("%i", &n);
    scanf("%i", &m);
    int** arr = (int**)malloc(n * sizeof(int*));
    for(i = 0; i < n; ++i){
        arr[i] = (int*)malloc(m * sizeof(int));
        for(j = 0; j < m; ++j){
            scanf("%i", &arr[i][j]);
        }
    }
    for(i = 0; i < n; ++i){
        int imax = i, jmax = 0;
        for(j = 0; j < m; ++j){
            if(arr[imax][jmax] < arr[i][j]){
                jmax = j;
            }
        }
        if(IsSaddlePoint(arr, n, imax, jmax)){
            printf("%i %i\n", imax, jmax);
            ++count_saddle;
        }
    }
    if(count_saddle == 0) printf("none");
    for(i = 0; i < n; ++i)
        free(arr[i]);
    free(arr);
    return 0;
}