#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

struct Stack{
    int *data;
    int cap;
    int top;
};

void InitStack(int n, struct Stack *s){
    int *data = calloc(n, sizeof(int));
    s->data = data;
    s->cap = n;
    s->top = 0;
}

void Push(struct Stack *s, int x){
    if(s->top != s->cap){
        s->data[s->top] = x;
        s->top = s->top + 1;
    }
}

int Pop(struct Stack *s){
    s->top = s->top - 1;
    return s->data[s->top];
}

int main(int args, char **argv){
    struct Stack s;
    InitStack(1000000, &s);
    // fgets(command, 5, stdin);
    while(true){
        char command[6];
        scanf("%s", command);
        if(strcmp(command, "CONST") == 0){
            int x = 0;
            scanf("%d", &x);
            Push(&s, x);
        }
        else if(strcmp(command, "ADD") == 0){
            int a, b = 0;
            a = Pop(&s);
            b = Pop(&s);
            Push(&s, a + b);
        }
        else if(strcmp(command, "SUB") == 0){
            int a, b = 0;
            a = Pop(&s);
            b = Pop(&s);
            Push(&s, a - b);
        }
        else if(strcmp(command, "MUL") == 0){
            int a, b = 0;
            a = Pop(&s);
            b = Pop(&s);
            Push(&s, a * b);
        }
        else if(strcmp(command, "DIV") == 0){
            int a, b = 0;
            a = Pop(&s);
            b = Pop(&s);
            Push(&s, a / b);
        }
        else if(strcmp(command, "MAX") == 0){
            int a, b = 0;
            a = Pop(&s);
            b = Pop(&s);
            Push(&s, MAX(a, b));
        }
        else if(strcmp(command, "MIN") == 0){
            int a, b = 0;
            a = Pop(&s);
            b = Pop(&s);
            Push(&s, MIN(a, b));
        }
        else if(strcmp(command, "NEG") == 0){
            int a = 0;
            a = Pop(&s);
            int neg_a = -1 * a;
            Push(&s, neg_a);
        }
        else if(strcmp(command, "DUP") == 0){
            int a = 0;
            a = Pop(&s);
            Push(&s, a);
            Push(&s, a);
        }
        else if(strcmp(command, "SWAP") == 0){
            int a, b = 0;
            a = Pop(&s);
            b = Pop(&s);
            Push(&s, a);
            Push(&s, b);
        }
        else if(strcmp(command, "END") == 0){
            int x = 0;
            x = Pop(&s);
            printf("%d", x);
            break;
        }
    }
    free(s.data);
    return 0;
}
