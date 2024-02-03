#include <stdio.h>

int main() {
    int row, col;
    scanf("%d", &row);
    scanf("%d", &col);
    int arr[row][col], rows[10], cols[10];
    for (int r = 0; r < row; r++) 
        for (int c = 0; c < col; c++) 
            scanf("%d", &arr[r][c]);
    for (int i = 0; i < 10; i++) {
        cols[i] = 100000000;
        rows[i] = -100000000;
    }
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++) {
            if (arr[r][c] > rows[r])
                rows[r] = arr[r][c];
            if (arr[r][c] < cols[c])
                cols[c] = arr[r][c];
        }
    int f = 0;
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            if (rows[r] == cols[c]) {
                f = 1;
                printf("%d %d", r, c);
            }
    if (f == 0)
        printf("none");
    return 0;
}