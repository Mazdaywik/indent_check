#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* maxNode;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (isEmpty(stack) || data > stack->top->maxNode->data) {
        newNode->maxNode = newNode;
    }
    else {
        newNode->maxNode = stack->top->maxNode;
    }

    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);

    return data;
}

int getMax(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    return stack->top->maxNode->data;
}

void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

typedef struct QueueMax {
    Stack stack1;
    Stack stack2;
} QueueMax;

void initQueue(QueueMax* queue) {
    initStack(&(queue->stack1));
    initStack(&(queue->stack2));
}

void enqueue(QueueMax* queue, int data) {
    push(&(queue->stack1), data);
}

int dequeue(QueueMax* queue) {
    if (isEmpty(&(queue->stack2))) {
        while (!isEmpty(&(queue->stack1))) {
            push(&(queue->stack2), pop(&(queue->stack1)));
        }
    }

    return pop(&(queue->stack2));
}

int getMaxInQueue(QueueMax* queue) {
    if (isEmpty(&(queue->stack1)) && isEmpty(&(queue->stack2))) {
        fprintf(stderr, "Error: Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    if (isEmpty(&(queue->stack1))) {
        return getMax(&(queue->stack2));
    }

    if (isEmpty(&(queue->stack2))) {
        return getMax(&(queue->stack1));
    }

    int maxStack1 = getMax(&(queue->stack1));
    int maxStack2 = getMax(&(queue->stack2));

    return (maxStack1 > maxStack2) ? maxStack1 : maxStack2;
}

int isQueueEmpty(QueueMax* queue) {
    return (isEmpty(&(queue->stack1)) && isEmpty(&(queue->stack2)));
}

void freeQueue(QueueMax* queue) {
    freeStack(&(queue->stack1));
    freeStack(&(queue->stack2));
}

int main() {
    QueueMax queue;
    initQueue(&queue);

    char operation[10];
    int value;

    while (1) {
        scanf("%s", operation);

        if (strcmp(operation, "ENQ") == 0) {
            scanf("%d", &value);
            enqueue(&queue, value);
        }
        else if (strcmp(operation, "DEQ") == 0) {
            printf("%d\n", dequeue(&queue));
        }
        else if (strcmp(operation, "MAX") == 0) {
            printf("%d\n", getMaxInQueue(&queue));
        }
        else if (strcmp(operation, "EMPTY") == 0) {
            printf("%s\n", isQueueEmpty(&queue) ? "true" : "false");
        }
        else if (strcmp(operation, "END") == 0) {
            break;
        }
    }

    freeQueue(&queue);

    return 0;
}