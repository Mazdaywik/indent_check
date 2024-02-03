#include <stdio.h>
#include <stdlib.h>

struct Row {
    int index;
    int max_value;
};

struct Col {
    int index;
    int min_value;
};

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int matrix[10][10];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    struct Row row_max[10];
    struct Col col_min[10];

    for (int i = 0; i < rows; i++) {
        row_max[i].index = i;
        row_max[i].max_value = matrix[i][0];
    }

    for (int j = 0; j < cols; j++) {
        col_min[j].index = j;
        col_min[j].min_value = matrix[0][j];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] > row_max[i].max_value)
                row_max[i].max_value = matrix[i][j];
        }
    }

    for (int j = 0; j < cols; j++) {
        for (int i = 1; i < rows; i++) {
            if (matrix[i][j] < col_min[j].min_value)
                col_min[j].min_value = matrix[i][j];
        }
    }

    int found = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == row_max[i].max_value && matrix[i][j] == col_min[j].min_value) {
                printf("%d %d\n", i, j);
                found = 1;
            }
        }
    }

    if (!found)
        printf("none\n");

    return 0;
}
