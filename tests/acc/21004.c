#include <stdio.h>
#include <stdlib.h>

#define max(first, second) first > second ? first : second

int main() {
    int lenArray, k;
    scanf("%d", &lenArray);
    int *array = calloc(lenArray, sizeof(int));
    for(int ind = 0; ind < lenArray; ind++){
        scanf("%d", &array[ind]);
    }

    scanf("%d", &k);

    int sum = 0, indStart = 0, indEnd = 0, maxSum;
    while (indEnd < lenArray){
        if (indEnd - indStart == k){
            sum = sum - array[indStart++] + array[indEnd++];
            maxSum = max(sum, maxSum);
        }else{
            sum = sum + array[indEnd++];
            if (indEnd - indStart == k){
                maxSum = sum;
            }
        }
    }
    printf("%d", maxSum);

    free(array);
    return 0;
}
