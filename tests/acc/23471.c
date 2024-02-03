#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int height = strtol(argv[1], NULL, 10) - 1;
    int width = strtol(argv[2], NULL, 10) - 1;
    char *text = argv[3];
    int len = strlen(text);
    if(width - len - 1 < 0 || height < 2)
    {
        printf("Error");
        return 0;
    }
    for(int i = 0; i <= height ; i++){
        for(int j = 0 ; j <= width ; j++){
            if(i==0||j==0||j==width||i==height)
                printf("*");
            else {
                if (i == height/2 && (width/2 - len/2 <= j && j <= width/2 + len/2)){
                    printf("%c", text[j - (width/2 - len/2)]);
                }else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}