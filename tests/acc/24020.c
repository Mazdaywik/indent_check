#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct Stack{ 
    int cap;
    int top;
    int *data;
};
void InitStack(struct Stack *s, int n){
    s->cap = n;
    s->top = 0;
    s->data = calloc(n, sizeof(int));

}
int StackEmpty(struct Stack *s){
    int empty = s->top;
    return empty;
}
void Push(struct Stack *s, int x){
    s->data[s->top] = x;
    s->top += 1;
}
int Pop(struct Stack *s){
    s->top -= 1;
    int x = s->data[s->top];
    return x;
}
void CONST(struct Stack *s, int x){
    Push(s, x);
}
void ADD(struct Stack *s){
    int a = Pop(s);
    int b = Pop(s);
    Push(s, a + b);
}
void SUB(struct Stack *s){
    int a = Pop(s);
    int b = Pop(s);
    Push(s, a - b);
}
void MUL(struct Stack *s){
    int a = Pop(s);
    int b = Pop(s);
    Push(s, a * b);
}
void DIV(struct Stack *s){
    int a = Pop(s);
    int b = Pop(s);
    Push(s, a / b);
}
void MAX(struct Stack *s){
    int a = Pop(s);
    int b = Pop(s);
    if (a > b){
        Push(s, a);
    }
    else{
        Push(s, b);
    }
}
void MIN(struct Stack *s){
    int a = Pop(s);
    int b = Pop(s);
    if (a > b){
        Push(s, b);
    }
    else{
        Push(s, a);
    }
}
void NEG(struct Stack *s){
    int a = Pop(s);
    Push(s, -a);
}
void DUP(struct Stack *s){
    int a = Pop(s);
    Push(s, a);
    Push(s, a);
}
void SWAP(struct Stack *s){
    int a = Pop(s);
    int b = Pop(s);
    Push(s, a);
    Push(s, b);
}
int main(){
    struct Stack s;
    char command[6] = "HELL";
    int x;
    InitStack(&s, 2 << 20);
    while (strcmp(command, "END")){
        scanf("%s", command);
        if (strcmp(command, "CONST") == 0){
            scanf("%d", &x);
            CONST(&s, x);
        }
        if (strcmp(command, "ADD") == 0){
            ADD(&s);
        }
        if (strcmp(command, "SUB") == 0){
            SUB(&s);
        }
        if (strcmp(command, "MUL") == 0){
            MUL(&s);
        }
        if (strcmp(command, "DIV") == 0){
            DIV(&s);
        }
        if (strcmp(command, "MAX") == 0){
            MAX(&s);
        }
        if (strcmp(command, "MIN") == 0){
            MIN(&s);
        }
        if (strcmp(command, "NEG") == 0){
            NEG(&s);
        }
        if (strcmp(command, "DUP") == 0){
            DUP(&s);
        }
        if (strcmp(command, "SWAP") == 0){
            SWAP(&s);
        }
    }
  printf("%d", Pop(&s));
  free(s.data);
}