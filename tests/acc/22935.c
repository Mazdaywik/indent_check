#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char **argv)
{
    int m, n, max_in_row, min_in_col, max_in_min, min_in_max, i, j, i_sad, j_sad;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    min_in_max = pow(2, 31);
    max_in_min = -pow(2,31);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) scanf("%d", &arr[i][j]);
    }
    for (i = 0; i < m; i++) {
        max_in_row = arr[i][0];
        for (j = 1; j < n; j++) {
            if (arr[i][j] > max_in_row) {
               max_in_row = arr[i][j];
           }
        }
        if (max_in_row < min_in_max) {
            min_in_max = max_in_row;
            i_sad = i;
        }
    }
    for (j = 0; j < n; j++) {
        min_in_col = arr[0][j];
        for (i = 1; i < m; i++) {
            if (arr[i][j] < min_in_col) {
               min_in_col = arr[i][j];
           }
        }
        if (min_in_col > max_in_min) {
            max_in_min = min_in_col;
            j_sad = j;
        }
    }
    if (max_in_min == min_in_max) {
        printf("%d %d", i_sad, j_sad);
    }
    else printf("none");
    return 0;
}