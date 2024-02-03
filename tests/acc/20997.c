#include <stdio.h>

int isElementInArray(int element, int Array){
    return Array & (1 << element);
}

int main() {
    int firstArray = 0, secondArray = 0, firstCount, secondCount, tempElement;
    
    scanf("%d", &firstCount);
    while (firstCount--){
        scanf("%d", &tempElement);
        firstArray |= (1<<tempElement);
    }
    
    scanf("%d", &secondCount);
    while (secondCount--){
        scanf("%d", &tempElement);
        secondArray |= (1 << tempElement);
    }
    
    int resultArray = firstArray & secondArray;
    for(int element = 0; element <= 31; element++){
        if(isElementInArray(element, resultArray))
            printf("%d ", element);
    }
    return 0;
}
