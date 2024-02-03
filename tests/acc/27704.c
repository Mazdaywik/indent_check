#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    long long data;
};

struct Stack {
    struct Node *top;
};

struct Stack CONST(struct Stack stack, long long element) {
    struct Node* new_const = malloc(sizeof(struct Node));
    new_const->data = element;
    new_const->next = stack.top;
    stack.top = new_const;
    return stack;
}

struct Stack ADD(struct Stack stack) {
    stack.top->next->data += stack.top->data;
    struct Node* top = stack.top->next;
    free(stack.top);
    stack.top = top;
    return stack;
}

struct Stack DUP(struct Stack stack) {
    stack = CONST(stack, stack.top->data);
    return stack;
}

struct Stack SWAP(struct Stack stack) {
    long long ch = stack.top->data;
    stack.top->data = stack.top->next->data;
    stack.top->next->data = ch;
    return stack;
}

struct Stack SUB(struct Stack stack) {
    stack.top->next->data = stack.top->data - stack.top->next->data;
    struct Node* top = stack.top->next;
    free(stack.top);
    stack.top = top;
    return stack;
}

struct Stack MUL(struct Stack stack) {
    stack.top->next->data *= stack.top->data;
    struct Node* top = stack.top->next;
    free(stack.top);
    stack.top = top;
    return stack;
}

struct Stack DIV(struct Stack stack) {
    stack.top->next->data = stack.top->data / stack.top->next->data;
    struct Node* top = stack.top->next;
    free(stack.top);
    stack.top = top;
    return stack;
}

struct Stack MAX(struct Stack stack) {
    if (stack.top->next->data < stack.top->data) {
        stack.top->next->data = stack.top->data;
    }
    struct Node* top = stack.top->next;
    free(stack.top);
    stack.top = top;
    return stack;
}

struct Stack MIN(struct Stack stack) {
    if (stack.top->next->data > stack.top->data) {
        stack.top->next->data = stack.top->data;
    }
    struct Node* top = stack.top->next;
    free(stack.top);
    stack.top = top;
    return stack;
}

struct Stack NEG(struct Stack stack) {
    stack.top->data = -1*stack.top->data;
    return stack;
}

int main() {
    struct Stack stack;
    stack.top = NULL;
  // gcc -ggdb 
  // valgrind
    char command[9];
    scanf("%s", command);
    while (strcmp(command, "END") != 0) {
        if (strcmp(command, "ADD") == 0) {
            stack = ADD(stack);
        }
        else if (strcmp(command, "CONST") == 0) {
            long long x;
            scanf("%lld", &x);
            stack = CONST(stack, x);
        }
        else if (strcmp(command, "DUP") == 0) {
            stack = DUP(stack);
        }
        else if (strcmp(command, "SWAP") == 0) {
            stack = SWAP(stack);
        }
        else if (strcmp(command, "SUB") == 0) {
            stack = SUB(stack);
        }
        else if (strcmp(command, "MUL") == 0) {
            stack = MUL(stack);
        }
        else if (strcmp(command, "DIV") == 0) {
            stack = DIV(stack);
        }
        else if (strcmp(command, "NEG") == 0) {
            stack = NEG(stack);
        }
        else if (strcmp(command, "MAX") == 0) {
            stack = MAX(stack);
        }
        else if (strcmp(command, "MIN") == 0) {
            stack = MIN(stack);
        }
        scanf("%s", command);
    }
    printf("%lld", stack.top->data);
    free(stack.top);
    return 0;
}