#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(long int** stack, int* top_cap, long int num) {
    if (top_cap[0] == top_cap[1]) {
        *stack = realloc(*stack, top_cap[1] * 2 * sizeof(long int));
        top_cap[1] *= 2;
    }
    (*stack)[top_cap[0]] = num;
    top_cap[0] += 1;
}

long int pop(long int* stack, int* top_cap) {
    top_cap[0] -= 1;
    return stack[top_cap[0]];
}

void CONST(long int** stack, int* top_cap) {
    long int num;
    scanf ("%ld", &num);
    push(stack, top_cap, num);
}

void ADD(long int** stack, int* top_cap) {
    long int comp1 = pop(*stack, top_cap);
    long int comp2 = pop(*stack, top_cap);
    push(stack, top_cap, comp1 + comp2);
}

void SUB(long int** stack, int* top_cap){
    long int comp1 = pop(*stack, top_cap);
    long int comp2 = pop(*stack, top_cap);
    push(stack, top_cap, comp1 - comp2);
}

void MUL(long int** stack, int* top_cap) {
    long int mult1 = pop(*stack, top_cap);
    long int mult2 = pop(*stack, top_cap);
    push(stack, top_cap, mult1 * mult2);
}

void DIV(long int** stack, int* top_cap) {
    long int mult1 = pop(*stack, top_cap);
    long int mult2 = pop(*stack, top_cap);
    push(stack, top_cap, mult1 / mult2);
}

void MAX(long int** stack, int* top_cap) {
    long int compare1 = pop(*stack, top_cap);
    long int compare2 = pop(*stack, top_cap);
    push(stack, top_cap, (compare1 > compare2) ? compare1 : compare2);
}

void MIN(long int** stack, int* top_cap) {
    long int compare1 = pop(*stack, top_cap);
    long int compare2 = pop(*stack, top_cap);
    push(stack, top_cap, (compare1 < compare2) ? compare1 : compare2);
}

void NEG(long int** stack, int* top_cap) {
    long int num = pop(*stack, top_cap);
    push(stack, top_cap, -num);
}

void DUP(long int** stack, int* top_cap) {
    long int dupl = (*stack)[top_cap[0] - 1];
    push(stack, top_cap, dupl);
}

void SWAP(long int** stack, int* top_cap) {
    long int copy = (*stack)[top_cap[0] - 2];
    (*stack)[top_cap[0] - 2] = (*stack)[top_cap[0] - 1];
    (*stack)[top_cap[0] - 1] = copy;
}


int main() {
    long int* stack = calloc (5, sizeof (long int));
    int top_cap[] = {0, 5};
    while (1) {
        char op[6];
        scanf("%s", op);
        if (strcmp(op, "CONST") == 0) {
            CONST(&stack, top_cap);
        } else if (strcmp(op, "ADD") == 0) {
            ADD(&stack, top_cap);
        } else if (strcmp(op, "SUB") == 0) {
            SUB(&stack, top_cap);
        } else if (strcmp(op, "MUL") == 0) {
            MUL(&stack, top_cap);
        } else if (strcmp(op, "DIV") == 0) {
            DIV(&stack, top_cap);
        } else if (strcmp(op, "MAX") == 0) {
            MAX(&stack, top_cap);
        } else if (strcmp(op, "MIN") == 0) {
            MIN(&stack, top_cap);
        } else if (strcmp(op, "NEG") == 0) {
            NEG(&stack, top_cap);
        } else if (strcmp(op, "DUP") == 0) {
            DUP(&stack, top_cap);
        } else if (strcmp(op, "SWAP") == 0) {
            SWAP(&stack, top_cap);
        } else {
            break;
        }
    }
    printf("%ld\n", stack[top_cap[0] - 1]);
    free(stack);
    return 0;
}