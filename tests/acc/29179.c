#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int cap, top;
    int *data;
};

void InitStack(struct Stack *stack, int n)
{
    stack->data = (int*)malloc(sizeof(int) * n);
    stack->cap = n;
    stack->top = 0;
}

int StackEmpty(struct Stack *stack)
{
    return stack->top == 0;
}

void Push(struct Stack *stack, int x)
{
    stack->data[stack->top] = x;
    stack->top++;
}

int Pop(struct Stack *stack)
{
    stack->top--;
    return stack->data[stack->top];
}

int main(){
    int n=100000,x,a,b;
    char act[6] = "NO";
    struct Stack stack;
    InitStack(&stack, n);
    do {
        if (strcmp(act,"CONST")==0){
            scanf("%d",&x);
            Push(&stack,x);
        }
        else if (strcmp(act,"ADD")==0)
        {
            a=Pop(&stack);
            b=Pop(&stack);
            Push(&stack,a+b);
        }
        else if (strcmp(act,"SUB")==0)
        {
            a=Pop(&stack);
            b=Pop(&stack);
            Push(&stack,a-b);
        }
        else if (strcmp(act,"MUL")==0)
        {
            a=Pop(&stack);
            b=Pop(&stack);
            Push(&stack,a*b);
        }
        else if (strcmp(act,"DIV")==0)
        {
            a=Pop(&stack);
            b=Pop(&stack);
            Push(&stack,a/b);
        }
        else if (strcmp(act,"MAX")==0)
        {
            a=Pop(&stack);
            b=Pop(&stack);
            Push(&stack,a>b?a:b);
        }
        else if (strcmp(act,"MIN")==0)
        {
            a=Pop(&stack);
            b=Pop(&stack);
            Push(&stack,a<b?a:b);
        }
        else if (strcmp(act,"NEG")==0)
        {
            a=Pop(&stack);
            Push(&stack,-a);
        }
        else if (strcmp(act,"DUP")==0)
        {
            a=Pop(&stack);
            Push(&stack,a);
            Push(&stack,a);
        }
        else if (strcmp(act,"SWAP")==0)
        {
            a=Pop(&stack);
            b=Pop(&stack);
            Push(&stack,a);
            Push(&stack,b);
        }
        scanf("%s",act);
    } while (strcmp(act,"END")!=0);
    printf("%d",Pop(&stack));
    free(stack.data);
}
