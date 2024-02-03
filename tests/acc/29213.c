#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STACK_SIZE 10000000
#define max(a, b) a > b ? a : b
typedef struct {
    int *stack;
    int top;
} Stack;

typedef struct {
    Stack *stackFace;
    Stack *stackFaceMax;
    Stack *stackMask;
    Stack *stackMaskMax;
} Queue;

void init(Queue* queue){
    queue->stackMaskMax->stack = malloc(MAX_STACK_SIZE * sizeof(int));
    queue->stackMask->stack = malloc(MAX_STACK_SIZE * sizeof(int));
    queue->stackFaceMax->stack = malloc(MAX_STACK_SIZE * sizeof(int));
    queue->stackFace->stack = malloc(MAX_STACK_SIZE * sizeof(int));
}

void push(Stack* s, int value) {
    s->stack[++s->top] = value;
}

int pop(Stack* s) {
    return s->stack[s->top--];
}

int up(Stack* s) {
    return s->stack[s->top];
}

void Enqueue(Queue* queue, int item) {
    push(queue->stackFace, item);
    if(queue->stackFaceMax->top == -1){
        push(queue->stackFaceMax, item);
        return;
    }
    push(queue->stackFaceMax, max(item, up(queue->stackFaceMax)));
}
int Dequeue(Queue* queue) {
    if(queue->stackMask->top == -1){
        while (queue->stackFace->top != -1){
            pop(queue->stackFaceMax);
            if(queue->stackMaskMax->top == -1){
                push(queue->stackMaskMax, up(queue->stackFace));
            }else {
                push(queue->stackMaskMax, max(up(queue->stackMaskMax), up(queue->stackFace)));
            }
            push(queue->stackMask, up(queue->stackFace));
            pop(queue->stackFace);
        }
    }
    pop(queue->stackMaskMax);
    return pop(queue->stackMask);
}

int QueueEmpty(Queue* queue) {
    return queue->stackFace->top == -1 && queue->stackMask->top == -1;
}

int Maximum(Queue* queue) {
    if(queue->stackFaceMax->top == -1)
        return up(queue->stackMaskMax);
    if(queue->stackMaskMax->top == -1)
        return up(queue->stackFaceMax);
    return max(up(queue->stackFaceMax), up(queue->stackMaskMax));
}

int main() {
    Stack stackFace;
    Stack stackFaceMax;
    stackFace.top = -1;
    stackFaceMax.top = -1;
    Stack stackMask;
    Stack stackMaskMax;
    stackMaskMax.top = - 1;
    stackMask.top = -1;
    Queue queue;
    queue.stackFaceMax = &stackFaceMax;
    queue.stackMaskMax = &stackMaskMax;
    queue.stackMask = &stackMask;
    queue.stackFace = &stackFace;
    init(&queue);
    int n, val;
    char operation[100];
    while (1) {
        scanf("%s", operation);
        if (strcmp(operation, "ENQ") == 0) {
            scanf("%d", &val);
            Enqueue(&queue, val);
        }
        else if (strcmp(operation, "DEQ") == 0) {
            printf("%d\n", Dequeue(&queue));
        }
        else if (strcmp(operation, "EMPTY") == 0) {
            printf("%s\n", QueueEmpty(&queue) ? "true" : "false");
        }
        else if (strcmp(operation, "END") == 0) {
            break;
        }else if (strcmp(operation, "MAX") == 0) {
            printf("%d\n", Maximum(&queue));
        }
    }
    free(queue.stackMaskMax->stack);
    free(queue.stackMask->stack);
    free(queue.stackFaceMax->stack);
    free(queue.stackFace->stack);
    return 0;
}