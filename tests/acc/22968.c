#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    char s[1000];
    strcpy(s, argv[3]);
    int width = atoi(argv[2]), height = atoi(argv[1]); 
    int i, j, splaceh, splacew;
    if ((width - 2 < strlen(s)) || (height < 3)) printf("Error\n");
    else {
        if (height % 2 == 0) splaceh = (height - 1) / 2;
        else splaceh = height / 2;
        splacew = (width - 2 - strlen(s)) / 2 + 1;
        for (j = 0; j < width; j++) printf("*");
        printf("\n");
        for (i = 1; i < height - 1; i++) {
            if (i == splaceh) {
                printf("*");
                for (j = 1; j < splacew; j++) printf(" ");
                printf("%s", s);
                for (j = splacew + strlen(s); j < width - 1; j++) printf(" ");
                printf("*\n");
            }
            else {
                printf("*");
                for (j = 1; j < width - 1; j++) printf(" ");
                printf("*\n");
            }
        }
        for (j = 0; j < width; j++) printf("*");
    }
    return 0;
}