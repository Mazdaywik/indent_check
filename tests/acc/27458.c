//источник - https://learnc.info/adt/stack.html

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 100000
typedef int T;

typedef struct Stack_tag {
    T data[STACK_MAX_SIZE];
    size_t size;
} Stack_t;


#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

void push(Stack_t *stack, const T value) {
    if (stack->size >= STACK_MAX_SIZE) {
        exit(STACK_OVERFLOW);
    }
    stack->data[stack->size] = value;
    stack->size++;
}

T pop(Stack_t *stack) {
    if (stack->size == 0) {
        exit(STACK_UNDERFLOW);
    }
    stack->size--;
    return stack->data[stack->size];
}

T peek(const Stack_t *stack) {
    if (stack->size <= 0) {
        exit(STACK_UNDERFLOW);
    }
    return stack->data[stack->size - 1];
}

T MAX(T a, T b){
    if(a > b)
        return a;
    return b;
}

T MIN(T a, T b){
    if(a > b)
        return b;
    return a;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quicksort(int arr[], int n1, int n2, Stack_t *stack_left, Stack_t *stack_right) {
    if (n2 - n1 < 1) {
        return;
    }
    int i = n1;
    int j = n2;
    int baza = arr[(i + j) / 2];
    while (i <= j) {
        while (arr[i] < baza) {
            i++;
        }
        while (arr[j] > baza) {
            j--;
        }
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    push(stack_left, n1);
    push(stack_right, j);
    push(stack_left, i);
    push(stack_right, n2);
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Stack_t stack_left;
    Stack_t stack_right;
    stack_left.size = 0;
    stack_right.size = 0;
    push(&stack_left, 0);
    push(&stack_right, n-1);
    while(stack_left.size)
        quicksort(arr, pop(&stack_left), pop(&stack_right), &stack_left, &stack_right);


    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}