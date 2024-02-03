#include <stdio.h>
#include <math.h>

int main(void) {

    int lines = 0;
    int rows = 0;
    scanf("%d%d", &lines, &rows);

    int array[lines][rows];

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < rows; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    int saddlepoint = 0;

    for (int i = 0; i < lines; i++) {

        saddlepoint = 1; 
        int maxLine = -pow(2, 31);
        int currRow = 0;

        for (int j = 0; j < rows; j++) {
            if (array[i][j] > maxLine) {
                maxLine = array[i][j];
                currRow = j;
            }
        }

        for (int line = 0; line < lines; line++) {
            if (array[line][currRow] < maxLine) {
                saddlepoint = 0;  
                break; 
            }
        }

        if (saddlepoint) { 
            printf("%d %d", i, currRow);
            break; 
        }
    }
    if (!saddlepoint) printf("none");
    return 0;
}