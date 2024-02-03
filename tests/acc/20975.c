#include <stdio.h>

int main(void) {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int matrix[10][10];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    //for (int m = 0; m < rows; m++){
    //    for (int k = 0; k < cols; k++){
    //        printf("%d", matrix[m][k]);
    //    }
    //}
    
    int saddle = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int current = matrix[i][j];
            int is_saddle = 1;
            for (int k = 0; k < rows; k++) {
                if (k != i && current > matrix[k][j]) {
                    is_saddle = 0;
                    break;
                }
            }
            for (int k = 0; k < cols; k++) {
                if (k != j && current < matrix[i][k]) {
                    is_saddle = 0;
                    break;
                }
            }
            if (is_saddle) {
                printf("%d %d\n", i, j);
                saddle = 1;
                break;
            }
        }
        if (saddle) {
            break; 
        }
    }
    
    if (!saddle) {
        printf("none\n");
    }
    
    return 0;
}