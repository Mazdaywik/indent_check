#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STACK_SIZE 100000

struct Task {
    int low, high;
} typedef Task;

typedef struct {
    Task stack[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack* s, Task value) {
    s->stack[++s->top] = value;
}

Task pop(Stack* s) {
    return s->stack[s->top--];
}

void sort(int l, int r, int *arr, Stack *s) {
    if(l >= r)
        return;
    int mid = arr[(l + r) / 2];
    int tmp1 = l, tmp2 = r;
    while (tmp1 <= tmp2) {
        while (arr[tmp1] < mid) {
            tmp1++;
        }
        while (arr[tmp2] > mid) {
            tmp2--;
        }
        if (tmp1 >= tmp2) {
            break;
        }
        int x = arr[tmp1];
        arr[tmp1] = arr[tmp2];
        arr[tmp2] = x;
        tmp1++, tmp2--;
    }
    Task t;
    t.low = l;
    t.high = tmp2;
    push(s, t);
    t.low = tmp2 + 1;
    t.high = r;
    push(s, t);
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Stack stack;
    stack.top = -1;
    Task t;
    t.low = 0;
    t.high = n - 1;
    push(&stack, t);
    while (stack.top != -1){
        t = pop(&stack);
        sort(t.low, t.high, arr, &stack);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}