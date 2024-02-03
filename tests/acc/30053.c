#include <stdio.h>

int main() {
    int rows, cols;
    
    scanf("%d %d", &rows, &cols);

    int matrix[10][10];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int current_element = matrix[i][j];
            
            int is_max_in_row = 1;
            for (int k = 0; k < cols; ++k) {
                if (matrix[i][k] > current_element) {
                    is_max_in_row = 0;
                    break;
                }
            }

            int is_min_in_col = 1;
            for (int k = 0; k < rows; ++k) {
                if (matrix[k][j] < current_element) {
                    is_min_in_col = 0;
                    break;
                }
            }

            if (is_max_in_row && is_min_in_col) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }

    printf("none\n");

    return 0;
}