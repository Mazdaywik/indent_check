#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack {
    int *data, top;
};
struct Stack InitStack(struct Stack s, int n) {
    s.data = (int*)malloc(n * sizeof(int));
    s.top = 0;
    return s;
}
void PushStack(struct Stack *s, int x) {
    s->data[s->top] = x;
    s->top++;
}
int PopStack(struct Stack *s) {
    s->top--;
    return s->data[s->top];
}
int main() {
    char operation[10];
    struct Stack s;
    int x, sum, dif, mul, division, a, b;
    s = InitStack(s, 10000000);
    scanf("%s", operation);
    while (strcmp(operation, "END") != 0) {
        if (strcmp(operation, "CONST") == 0) {
            scanf("%d", &x);
            PushStack(&s, x);
        }
        else if (strcmp(operation, "ADD") == 0) {
            sum = PopStack(&s) + PopStack(&s);
            PushStack(&s, sum);
        }
        else if (strcmp(operation, "SUB") == 0) {
            dif = PopStack(&s) - PopStack(&s);
            PushStack(&s, dif);
        }
        else if (strcmp(operation, "MUL") == 0) {
            mul = PopStack(&s) * PopStack(&s);
            PushStack(&s, mul);
        }
        else if (strcmp(operation, "DIV") == 0) {
            division = PopStack(&s) / PopStack(&s);
            PushStack(&s, division);
        }
        else if (strcmp(operation, "MAX") == 0) {
            a = PopStack(&s);
            b = PopStack(&s);
            if (a > b) PushStack(&s, a);
            else PushStack(&s, b);
        }
        else if (strcmp(operation, "MIN") == 0) {
            a = PopStack(&s);
            b = PopStack(&s);
            if (a < b) PushStack(&s, a);
            else PushStack(&s, b);
        }
        else if (strcmp(operation, "NEG") == 0) {
            PushStack(&s, -PopStack(&s));
        }
        else if (strcmp(operation, "DUP") == 0) {
            a = PopStack(&s);
            PushStack(&s, a);
            PushStack(&s, a);
        }
        else if (strcmp(operation, "SWAP") == 0) {
            a = PopStack(&s);
            b = PopStack(&s);
            PushStack(&s, a);
            PushStack(&s, b);
        }
        scanf("%s", operation);
    }
    printf("%d", PopStack(&s));
    free(s.data);
}