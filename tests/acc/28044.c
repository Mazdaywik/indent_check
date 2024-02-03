#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(a, b) ((a > b) ? (b) : (a)) 

int sum;

void swap(int *a, int *b) { 
    int temp = *a;
    *a = *b;
    *b = temp;
}


int countGeneral(char *left, char *right) {
    int count = 0;
    int lenLeft = strlen(left); 
    int lenRight = strlen(right);

    for (int i = 1; i <= MIN(lenLeft, lenRight); ++i) { 
        int flag = 1;
        int indexLeft = lenLeft - i;
        int indexRight = 0;
        for (int j = 0; j < i; ++j) {
            if (left[indexLeft + j] != right[indexRight + j]) { 
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            count = i;
        }
    }

    return count;
}


void permute(int arr[], int start, int end, int **delta, int lenSuperStr) 
{
    if (start == end) {
        int currentLength = lenSuperStr;
    
        for (int i = 0; i < end; ++i) {
            currentLength -= delta[arr[i]][arr[i+1]];
        }

        sum = MIN(currentLength, sum);
    } else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);
            permute(arr, start + 1, end, delta, lenSuperStr);
            swap(&arr[start], &arr[i]);
        }
    }
}

int main(){
    int n, lenSuperStr = 0;

    scanf("%d", &n);

    char** strings = (char**)malloc(sizeof(char*) * n);  
    int** delta = (int**)malloc(sizeof(int*) * n);       

    for (int i = 0; i < n; ++i) {
        strings[i] = (char*)malloc(sizeof(char) * 1001);
        scanf("%1000s", strings[i]);
        lenSuperStr += strlen(strings[i]);
    }

    sum = lenSuperStr;

    for (int i = 0; i < n; ++i) {
        delta[i] = (int*)malloc(sizeof(int) * n);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                delta[i][j] = countGeneral(strings[i], strings[j]);
            } else {
                delta[i][j] = 0;
            }
        }
    }

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }

    permute(arr, 0, n - 1, delta, lenSuperStr); 

    printf("%d\n", sum);

    for (int i = 0; i < n; ++i){
        free(delta[i]);
        free(strings[i]);
    }

    free(delta);
    free(strings);
    free(arr); 

    return 0;    
}
