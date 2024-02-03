#include <stdio.h>

int main() {
    int rows, cols;

    scanf("%d", &rows);
    scanf("%d", &cols);

    int matrix[10][10];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int is_saddle_point = 1;

            for (int k = 0; k < rows; ++k) {
                if (matrix[k][j] < matrix[i][j]) {
                    is_saddle_point = 0;
                    break;
                }
            }

            for (int k = 0; k < cols; ++k) {
                if (matrix[i][k] > matrix[i][j]) {
                    is_saddle_point = 0;
                    break;
                }
            }

            if (is_saddle_point) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }

    printf("none\n");

    return 0;
}
