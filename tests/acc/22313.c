#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int matrix[10][10];
    int minn[10] = {0};
    int maxx[10] = {0};
    
    for (int i = 0; i < 10; i++) {
        minn[i] = INT_MAX;
        maxx[i] = INT_MIN;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] > maxx[i]) {
                maxx[i] = matrix[i][j];
            }
            if (matrix[i][j] < minn[j]) {
                minn[j] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maxx[i] == minn[j]) {
                printf("%i %i", i, j);
                return 0;
            }
        }
    }
    printf("none\n");
    return 0;
}