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

int main(int argc, char *argv[]) {
    Stack_t stack;
    stack.size = 0;
    char now_command[10];
    scanf("%s", now_command);
    while (strcmp(now_command, "END")){
        if(!strcmp(now_command, "CONST")){
            T x;
            scanf("%d", &x);
            push(&stack, x);
        }
        if(!strcmp(now_command, "ADD")){
            push(&stack, pop(&stack) + pop(&stack));
        }

        if(!strcmp(now_command, "SUB")){
            push(&stack, pop(&stack) - pop(&stack));
        }
        if(!strcmp(now_command, "MUL")){
            push(&stack, pop(&stack) * pop(&stack));
        }
        if(!strcmp(now_command, "DIV")){
            push(&stack, pop(&stack) / pop(&stack));
        }
        if(!strcmp(now_command, "MAX")){
            push(&stack, MAX(pop(&stack), pop(&stack)));
        }
        if(!strcmp(now_command, "MIN")){
            push(&stack, MIN(pop(&stack), pop(&stack)));
        }
        if(!strcmp(now_command, "NEG")){
            push(&stack, -pop(&stack));
        }
        if(!strcmp(now_command, "DUP")){
            push(&stack, peek(&stack));
        }
        if(!strcmp(now_command, "SWAP")){
            T a = pop(&stack);
            T b = pop(&stack);
            push(&stack, a);
            push(&stack, b);
        }
        scanf("%s", now_command);
    }
    printf("%d", peek(&stack));
    return 0;
}
