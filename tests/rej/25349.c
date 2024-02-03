#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 4){printf("Usage: frame <height> <width> <text>"); return 0;}
    
    int a=atoi(argv[1]);
    int b=atoi(argv[2]);
    char *t = argv[3];
    if (a < 3 || b-2 < strlen(t)){
        printf("Error");}else{
        int k1 = a/2;
        if(a%2==0){k1=k1-1;}
        int k2 = (b - strlen(t)-2)/2;
        for(int i = 0; i < b; i++){printf("*");}
        printf("\n");
        for (int i = 0; i < a-2; i++){
            if (i+1 == k1){
                printf("*");
                for(int j = 0; j < k2; j++){printf(" ");}
                printf("%s", t);
                for(int j = 0; j < b-2-strlen(t)-k2;j++){printf(" ");}
                printf("*");
                printf("\n");
            }else{
                printf("*");
                for(int j = 0; j < b-2; j++){printf(" ");}
                printf("*");
                printf("\n");
            }
        }
        for(int i = 0; i < b; i++){printf("*");}
    }
    return 0;
}