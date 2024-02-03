#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_frame(int height, int width, char *text) {
    if (height < 3 || width < 3) {
        printf("Error\n");
        return;
    }

    if (strlen(text) > width - 2) {
        printf("Error\n");
        return;
    }

    int top_bottom_padding = (height - 3) / 2;
    int left_right_padding = (width - strlen(text) - 2) / 2;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i == 0 || i == height - 1) && (j == 0 || j == width - 1)) {
                printf("*");
            } else if (i == 0 || i == height - 1) {
                printf("*");
            } else if (j == 0 || j == width - 1) {
                printf("*");
            } else if (i == top_bottom_padding + 1 && j == left_right_padding + 1) {
                printf("%s", text);
                j += strlen(text) - 1;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }

    int height = atoi(argv[1]);
    int width = atoi(argv[2]);
    char *text = argv[3];

    print_frame(height, width, text);

    return 0;
}
