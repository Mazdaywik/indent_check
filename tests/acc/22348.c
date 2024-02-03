#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
    if (argc != 4){
        printf("%s", "Usage: frame <height> <width> <text>");
        return 0;
    }
    int height = atoi(argv[1]), width = atoi(argv[2]);
    char *text = argv[3];
    if(height < 3 || width <= strlen(text)+1){
        printf("%s", "Error");
        return 0;
    }
    for(int i=0; i < width; i++) printf("%s", "*");
    printf("%c", '\n');
    int locationh = (height+1)/2 - 1, locationw_start = (width-strlen(text))/2 +1;
    int locationw_end = (width+strlen(text))/2 +1;
    for(int i=1; i<height-1; i++){
        printf("%s", "*");
        if(locationh != i) {
            for (int j=1; j<width-1; j++) printf("%s", " ");
            printf("%s%c", "*", '\n');
            continue;
        }
        for(int j=1; j<locationw_start-1; j++) printf("%s", " ");
        for(int j=0; j<locationw_end - locationw_start; j++) printf("%c", text[j]);
        for(int j=locationw_end; j<=width-1; j++) printf("%s", " ");
        printf("%s%c", "*", '\n');
    }
    for(int i=0; i < width; i++) printf("%s", "*");
    return 0;
}