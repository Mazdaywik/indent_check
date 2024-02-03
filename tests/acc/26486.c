#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void InitStack(Stack *s) {
    s->top = NULL;
}

void Push(Stack *s, int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = s->top;
    s->top = newNode;
}

int Pop(Stack *s) {
    if (s->top == NULL) {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(1);
    }
    int x = s->top->data;
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return x;
}

int IsEmpty(Stack *s) {
    return (s->top == NULL);
}

int main() {
    Stack stack;
    InitStack(&stack);

    char op[10];
    int x;
    while (1) {
        scanf("%s", op);
        if (op[0] == 'C') {
            scanf("%d", &x);
            Push(&stack, x);
        } else if (op[0] == 'A') {
            Push(&stack, Pop(&stack) + Pop(&stack));
        } else if (op[0] == 'S' && op[1] == 'U') {
            int a = Pop(&stack);
            int b = Pop(&stack);
            Push(&stack, a - b);
        } else if ((op[0] == 'M') && (op[1] == 'U')) {
            Push(&stack, Pop(&stack) * Pop(&stack));
        } else if (op[0] == 'D'&& op[1] == 'I') {
            int a = Pop(&stack);
            int b = Pop(&stack);
            Push(&stack, a / b);
        } else if (op[0] == 'N') {
            int a = Pop(&stack);
            Push(&stack, -a);
        } else if (op[0] == 'M' && op[1] == 'A') {
            int a = Pop(&stack);
            int b = Pop(&stack);
            if (a > b) Push(&stack, a);
            else Push(&stack, b);
        } else if (op[0] == 'M' && op[1] == 'I') {
            int a = Pop(&stack);
            int b = Pop(&stack);
            if (a > b) Push(&stack, b);
            else Push(&stack, a);
        } else if (op[0] == 'D' && op[1] == 'U') {
            int a = Pop(&stack);
            Push(&stack, a);
            Push(&stack, a);
        } else if (op[0] == 'S' && op[1] == 'W') {
            int b = Pop(&stack);
            int a = Pop(&stack);
            Push(&stack, b);
            Push(&stack, a);
        } else if (op[0] == 'E' && op[1] == 'N' && op[2] == 'D') {
            break;
        }
    }

    printf("%d\n", Pop(&stack));

    return 0;
}
