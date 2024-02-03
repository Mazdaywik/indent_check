#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Stack
{
    int cap, top;
    long *data;
};

void InitStack(struct Stack *my_stack, int n)
{
    my_stack->data = (long *)malloc(n * sizeof(long));
    my_stack->cap = n;
    my_stack->top = 0;
}

int StackEmpty(struct Stack *my_stack)
{
    return (my_stack->top == 0);
}

void Push(struct Stack *my_stack, long number)
{
    if (my_stack->cap == my_stack->top)
        printf("переполнение\n");
    else
    {
        (my_stack->data)[my_stack->top] = number;
        my_stack->top++;
    }
}

long Pop(struct Stack *my_stack)
{
    if (StackEmpty(my_stack))
        printf("опустошение\n");
    else
    {
        my_stack->top--;
        return (my_stack->data)[my_stack->top];
    }
}

int main()
{
    struct Stack my_stack;
    InitStack(&my_stack, 1000000);

    char word[6];
    scanf("%s", word);

    while (strcmp(word, "END") != 0)
    {
        if (strcmp(word, "CONST") == 0)
        {
            long number;
            scanf("%ld", &number);
            Push(&my_stack, number);
        }

        else if (strcmp(word, "ADD") == 0)
            Push(&my_stack, Pop(&my_stack) + Pop(&my_stack));

        else if (strcmp(word, "SUB") == 0)
            Push(&my_stack, Pop(&my_stack) - Pop(&my_stack));

        else if (strcmp(word, "MUL") == 0)
            Push(&my_stack, Pop(&my_stack) * Pop(&my_stack));

        else if (strcmp(word, "DIV") == 0)
            Push(&my_stack, Pop(&my_stack) / Pop(&my_stack));
        
        else if (strcmp(word, "MAX") == 0)
            Push(&my_stack, (long)fmax(Pop(&my_stack), Pop(&my_stack)));

        else if (strcmp(word, "MIN") == 0)
            Push(&my_stack, (long)fmin(Pop(&my_stack), Pop(&my_stack)));

        else if (strcmp(word, "NEG") == 0)
            Push(&my_stack, -Pop(&my_stack));

        else if (strcmp(word, "DUP") == 0)
        {
            long number = Pop(&my_stack);
            Push(&my_stack, number);
            Push(&my_stack, number);
        }

        else if (strcmp(word, "SWAP") == 0)
        {
            long number_1 = Pop(&my_stack);
            long number_2 = Pop(&my_stack);
            Push(&my_stack, number_1);
            Push(&my_stack, number_2);
        }
        
        scanf("%s", word);
    }

    printf("%ld", my_stack.data[my_stack.top - 1]);
    free(my_stack.data);

    return 0;
}