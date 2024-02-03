#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 100000000

struct para{
    int num;
    int max;
};

typedef struct para T;

typedef struct Stack_tag {
    T *data;
    size_t size;
} Stack_t;


#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

int MAX(int a, int b){
    if(a > b)
        return a;
    return b;
}

void push(Stack_t *stack, const int value) {
    if (stack->size >= STACK_MAX_SIZE) {
        exit(STACK_OVERFLOW);
    }
    stack->data[stack->size].num = value;
    if(stack->size>0)
        stack->data[stack->size].max = MAX(value, stack->data[stack->size-1].max);
    else
        stack->data[stack->size].max = value;
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

int main(int argc, char *argv[]) {
    Stack_t stack1;
    stack1.size = 0;
    Stack_t stack2;
    stack2.size = 0;
    stack1.data = calloc(STACK_MAX_SIZE , sizeof(T));
    stack2.data = calloc(STACK_MAX_SIZE , sizeof(T));
    char now_command[10];
    scanf("%s", now_command);
    while (strcmp(now_command, "END")){
        if(!strcmp(now_command, "DEQ"))
            printf("%d\n", pop(&stack2).num);
        if(!strcmp(now_command, "ENQ")){
            int val;
            scanf("%d", &val);
            push(&stack1, val);
        }
        if(!strcmp(now_command, "EMPTY"))
            printf((stack1.size + stack2.size) ? "false\n" : "true\n");
        if(!strcmp(now_command, "MAX")){
            if(stack2.size == 0)
                printf("%d\n", peek(&stack1).max);
            else if(stack1.size == 0)
                printf("%d\n", peek(&stack2).max);
            else
                printf("%d\n", MAX(peek(&stack2).max, peek(&stack1).max));
        }
        if(stack2.size == 0)
            while (stack1.size)
                push(&stack2, pop(&stack1).num);
        scanf("%s", now_command);
    }
    free(stack1.data);
    free(stack2.data);
    return 0;
}