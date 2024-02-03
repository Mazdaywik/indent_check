#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define SIZE 8
int main()
{
    int firstArr[SIZE], secondArr[SIZE];
    int thirdArr[SIZE];
    int i, j, k, index = 0;
    for(i = 0; i < SIZE; ++i){
        thirdArr[i] = -1;
    }
    for(i = 0; i < SIZE; ++i){
        scanf("%i", &firstArr[i]);
    }
    for(i = 0; i < SIZE; ++i){
        scanf("%i", &secondArr[i]);
    }
    for(i = 0; i < SIZE; ++i){
        bool isFind = false;
        for(j = 0; j < SIZE; ++j){
            if(firstArr[i] == secondArr[j]){
                bool isFlag = false;
                for(k = 0; k < SIZE; ++k)
                    if(j == thirdArr[k]) isFlag = true;
                if(!isFlag){
                    isFind = true;
                    thirdArr[index++] = j;
                    break;
                }
            }
        }
        if(!isFind){
            printf("no");
            return 0;
        }
    }
    printf("yes");
    return 0;
}