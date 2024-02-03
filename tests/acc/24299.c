#include <stdio.h>
#include <stdlib.h>

struct Task {
    int low, high;
};

struct stack{
    struct Task task;
    struct stack *pred;
};

void swap(int *array, int a, int b){
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

struct stack *push(struct stack *pred, int start, int end){
    struct stack *new = malloc(sizeof(struct stack));
    new->pred = pred;
    new->task.low = start;
    new->task.high = end;
    return new;
}

void quicksort(int* array, int start, int end){
    struct stack *Stack = malloc(sizeof(struct stack));
    Stack->pred = NULL;
    Stack->task.low = -1;
    Stack->task.high = -1;
    Stack = push(Stack, start, end);
    while (Stack->pred!=NULL) {
        struct stack *pred = Stack->pred;
        start = Stack->task.low;
        end = Stack->task.high;
        free(Stack);
        Stack = pred;
        if(start >= end)
            continue;
        int mid = array[(start + end) / 2];
        int left = start, right = end;
        while (left < right) {
            while (array[left] < mid)
                left++;
            while (array[right] > mid)
                right--;
            if (left <= right) {
                swap(array, left, right);
                left++;
                right--;
            }
        }
        Stack = push(Stack, start, right);
        Stack = push(Stack, left, end);
    }
    free(Stack);
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    int *array = calloc(n, sizeof(int));
    for(int i = 0 ; i < n; i++){
        scanf("%d", &array[i]);
    }
    quicksort(array, 0, n-1);
    for(int i = 0 ; i < n ; i++)
        printf("%d ", array[i]);
    free(array);
    return 0;
}

