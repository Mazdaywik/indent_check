#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>"); 
        return 0; 
    }

    int height = atoi(argv[1]);
    int width = atoi(argv[2]);
    char *text = argv[3];

    if (height >= 3 && (size_t)width >= (2 + strlen(text))) 
    {
        for (int i = 0; i < height; ++i) 
        {
            if(i == 0 || i == height - 1) 
            {
                for(int j = 0; j < width; ++j)
                {
                    printf("*");
                }
                printf("\n");
            }
            else if(i == (height - 1) / 2) 
            {
                printf("*"); 
                for (int j = 1; j < (width - (int)strlen(text)) / 2; ++j) 
                {
                    printf(" ");
                }

                printf("%s", text); 

                for (int j = 1; j < width - ((width - (int)strlen(text)) / 2 + (int)strlen(text)); ++j) 
                {
                    printf(" ");
                }
                printf("*\n"); 
            }
            else
            {
                printf("*"); 
                for (int j = 1; j < width - 1; ++j)
                {
                    printf(" ");
                }
                printf("*\n");
            }
        }
    }
    else
    {
        printf("Error"); 
        return 0;
    }

    return 0;
}
