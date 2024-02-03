#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_MAX_SIZE 404404
typedef int T;
T maxel(T a, T b)
{
	return a < b ? b : a;
}

typedef struct Stack_tag
{
	T data[STACK_MAX_SIZE];
	size_t size;
}

Stack_t;
void push(Stack_t *stack, const T value)
{
	stack->data[stack->size++] = value;
}

T pop(Stack_t *stack)
{
	return stack->data[--stack->size];
}

void add(Stack_t *stack)
{
	push(stack, pop(stack) + pop(stack));
}

void sub(Stack_t *stack)
{
	push(stack, pop(stack) - pop(stack));
}

void mul(Stack_t *stack)
{
	push(stack, pop(stack) *pop(stack));
}

void max(Stack_t *stack)
{
	push(stack, maxel(pop(stack), pop(stack)));
}

void min(Stack_t *stack)
{
	T a = pop(stack), b = pop(stack);
	push(stack, a + b - maxel(a, b));
}

void ddiv(Stack_t *stack)
{
	push(stack, (T)(pop(stack) / pop(stack)));
}

void neg(Stack_t *stack)
{
	push(stack, pop(stack) *-1);
}

void swap(Stack_t *stack)
{
	T a = pop(stack), b = pop(stack);
	push(stack, a);
	push(stack, b);
}

void dup(Stack_t *stack)
{
	T a = pop(stack);
	push(stack, a);
	push(stack, a);
}

int main()
{
	Stack_t stack;
	stack.size = 0;
	while (1)
	{
		char cmd[2023];
		scanf("%s", cmd);
		if (strcmp(cmd, "CONST") == 0)
		{
			T arg;
			scanf("%d", &arg);
			push(&stack, arg);
		}
		else if (strcmp(cmd, "ADD") == 0) add(&stack);
		else if (strcmp(cmd, "SUB") == 0) sub(&stack);
		else if (strcmp(cmd, "MUL") == 0) mul(&stack);
		else if (strcmp(cmd, "DIV") == 0) ddiv(&stack);
		else if (strcmp(cmd, "MAX") == 0) max(&stack);
		else if (strcmp(cmd, "MIN") == 0) min(&stack);
		else if (strcmp(cmd, "NEG") == 0) neg(&stack);
		else if (strcmp(cmd, "DUP") == 0) dup(&stack);
		else if (strcmp(cmd, "SWAP") == 0) swap(&stack);
		else if (strcmp(cmd, "END") == 0)
		{
			printf("%d\n", pop(&stack));
			break;
		}
	}
}
