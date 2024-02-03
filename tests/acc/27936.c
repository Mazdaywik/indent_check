#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_frame(int height, int width, char *text);

int main(int arg_count, char **arg_values)
{
    if (arg_count != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }

    int frame_height = atoi(arg_values[1]),
        frame_width = atoi(arg_values[2]);

    char *display_text = arg_values[3];
    int text_length = strlen(display_text);

    if (text_length > frame_width - 2 || frame_height < 3)
    {
        printf("Error\n");
        return 0;
    }

    print_frame(frame_height, frame_width, display_text);

    return 0;
}

void print_frame(int height, int width, char *text)
{
    int text_length = strlen(text);

    if (text_length > width - 2 || height < 3)
    {
        printf("Error\n");
        return;
    }

    int text_row = (height + 1) / 2,
        text_start = (width - text_length) / 2 + 1,
        text_end = text_start + text_length - 1;

    for (int row = 1; row <= height; row++)
    {
        for (int col = 1; col <= width; col++)
        {
            if (row == 1 || row == height || col == 1 || col == width)
            {
                printf("*");
                if (col == width)
                    printf("\n");
            }
            else if (row == text_row)
            {
                if (col >= text_start && col <= text_end)
                    printf("%c", text[col - text_start]);
                else
                    printf(" ");
            }
            else
                printf(" ");
        }
    }
}
