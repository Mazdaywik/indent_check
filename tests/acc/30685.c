#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int cap;
    int top;
    int *data;
};

void InitStack(struct Stack *s, int n) {
    (*s).cap = n;
    (*s).top = 0;
    (*s).data = calloc(n, sizeof(int));
}

void push(struct Stack *s, int x) {
    (*s).data[(*s).top] = x;
    (*s).top++;
}

int pop(struct Stack *s) {
    (*s).top--;
    return (*s).data[(*s).top];
}

void CONST(struct Stack *s, int x) {
    push(s, x);
}

void ADD(struct Stack *s) {
    int a = pop(s);
    int b = pop(s);
    push(s, a+b);
}
void SUB(struct Stack *s) {
    int a = pop(s);
    int b = pop(s);
    push(s, a - b);
}

void MUL(struct Stack *s) {
    int a = pop(s);
    int b = pop(s);
    push(s, a * b);	
}

void DIV(struct Stack *s) {
    int a = pop(s);
    int b = pop(s);
    push(s, a / b);	
	
}
void MAX(struct Stack *s) {
    int a = pop(s);
    int b = pop(s);
    push(s, (a > b) ? a : b);
}
void MIN(struct Stack *s) {
    int a = pop(s);
    int b = pop(s);
    push(s, (a < b) ? a : b);
}

void NEG(struct Stack *s) {
    int a = pop(s);
    push(s, -a);
}

void DUP(struct Stack *s) {
    int a = pop(s);
    push(s, a);
    push(s, a);
}

void SWAP(struct Stack *s) {
    int a = pop(s);
    int b = pop(s);
    push(s, a);
    push(s, b);
}


int main() {
    struct Stack stack;
    char action[6];
    int c;
    InitStack(&stack, 200000);
	
    while (1) {
    	scanf("%s", action);
		
        if (strcmp(action, "CONST") == 0) {
            scanf("%d", &c);
	    CONST(&stack, c);
        }
		
	else if (strcmp(action, "ADD") == 0) ADD(&stack);
			
	else if (strcmp(action, "SUB") == 0) SUB(&stack);
		
        else if (strcmp(action, "MUL") == 0) MUL(&stack);
        
	else if (strcmp(action, "DIV") == 0) DIV(&stack);
        
    	else if (strcmp(action, "MAX") == 0) MAX(&stack);

        else if (strcmp(action, "MIN") == 0) MIN(&stack);
		
        else if (strcmp(action, "NEG") == 0) NEG(&stack);
		
	else if (strcmp(action, "DUP") == 0) DUP(&stack);
		
	else if (strcmp(action, "SWAP") == 0) SWAP(&stack);
	    
	else if (strcmp(action, "END") == 0) {
	    printf("%d", pop(&stack));
            break;
	}
    }
    free(stack.data);
    return 0;
}