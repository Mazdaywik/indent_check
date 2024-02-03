#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    int height = atoi(argv[1]);
    int width = atoi(argv[2]);
    char *text = argv[3];
    if (strlen(text) + 2 > width) {
        printf("Error\n");
        return 0;
    }
    for (int i = 0; i + 1 < (height + 1) / 2; i++) {
        if (i == 0) {
            for (int j = 0; j < width; j++) {
                printf("*");
            }
            printf("\n");
        } else {
            for (int j = 0; j < width; j++) {
                if (j == 0 || j + 1 == width) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    printf("*");
    for (int j = 0; j < (width - 2 - strlen(text)) / 2; j++) {
        printf(" ");
    }
    printf("%s", text);
    for (int j = 0; j < width - (width - 2 - strlen(text)) / 2 - 2 - strlen(text); j++) {
        printf(" ");
    }
    printf("*\n");
    for (int i = 0; i < height - (height + 1) / 2; i++) {
        if (i == height - (height + 1) / 2 - 1) {
            for (int j = 0; j < width; j++) {
                printf("*");
            }
            printf("\n");
        } else {
            for (int j = 0; j < width; j++) {
                if (j == 0 || j + 1 == width) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}