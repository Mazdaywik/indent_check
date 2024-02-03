#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int *data;
    int cap;
    int top;
};

void InitStack(struct Stack *s, int n)
{
    s->data = (int*) calloc(n, sizeof(int));
    s->cap = n;
    s->top = 0;
}

int StackEmpty(struct Stack *s)
{
    return (s->top == 0);
}

void Push(struct Stack *s, int x)
{
    if (s->top == s->cap) printf("error");
    else {
        s->data[s->top] = x;
        s->top++;
    }
}

int Pop(struct Stack *s)
{
    s->top--;
    return s->data[s->top];
}

int main()
{
    char action[6];
    scanf("%s", action);
    
    struct Stack stack;
    InitStack(&stack, 100000);
    
    while (strcmp("END", action) != 0) {
        if (strcmp("CONST", action) == 0) {
            int x;
            scanf("%d", &x);
            Push(&stack, x);
        }
        else if (strcmp("ADD", action) == 0) {
            int a = Pop(&stack);
            int b = Pop(&stack);
            Push(&stack, a + b);
        }
        else if (strcmp("SUB", action) == 0) {
            int a = Pop(&stack);
            int b = Pop(&stack);
            Push(&stack, a - b);
        }
        else if (strcmp("MUL", action) == 0) {
            int a = Pop(&stack);
            int b = Pop(&stack);
            Push(&stack, a * b);
        }
        else if (strcmp("DIV", action) == 0) {
            int a = Pop(&stack);
            int b = Pop(&stack);
            Push(&stack, a / b);
        }
        else if (strcmp("MAX", action) == 0) {
            int a = Pop(&stack);
            int b = Pop(&stack);
            if (a > b)
                Push(&stack, a);
            else
                Push(&stack, b);
        }
        else if (strcmp("MIN", action) == 0) {
            int a = Pop(&stack);
            int b = Pop(&stack);
            if (a > b)
                Push(&stack, b);
            else
                Push(&stack, a);
        }
        else if (strcmp("NEG", action) == 0) {
            int a = Pop(&stack);
            Push(&stack, -a);
        }
        else if (strcmp("DUP", action) == 0) {
            int a = Pop(&stack);
            Push(&stack, a);
            Push(&stack, a);
        }
        else if (strcmp("SWAP", action) == 0) {
            int a = Pop(&stack);
            int b = Pop(&stack);
            Push(&stack, a);
            Push(&stack, b);
        }
        scanf("%s", action);
    }
    int answer = Pop(&stack);
    printf("%d ", answer);
    free(stack.data);
    return 0;
}
