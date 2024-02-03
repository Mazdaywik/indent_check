#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct stack 
{
    int* el;
    int ind;
};

struct stack Stack;

void CONST(int x)
{
    Stack.el[Stack.ind++]=x;
}

int POP()
{
    return Stack.el[--Stack.ind];
}

void ADD()
{
    CONST(POP()+POP());
}

void SUB()
{
    CONST(POP()-POP());
}

void MUL()
{
    CONST(POP()*POP());
}

void DIV()
{
    CONST(POP()/POP());
}

void MAX()
{
    CONST(fmax(POP(),POP()));
}

void MIN()
{
    CONST(fmin(POP(),POP()));
}

void NEG()
{
    CONST(-POP());
}

void DUP()
{
    CONST(Stack.el[Stack.ind-1]);
}

void SWAP()
{
    int a=POP();
    int b=POP();
    CONST(a);
    CONST(b);
}

int main() 
{
    int n;
    scanf("%d", &n);
    Stack.el= calloc(100000, sizeof (int));
    char command[100];
    scanf("%s",command);
     while(strcmp(command, "END") != 0)
     {
        if (strcmp(command, "CONST") == 0)
        {
            int x;
            scanf("%d", &x);
            CONST(x);
        }
        else if (strcmp(command, "ADD") == 0) 
            ADD();
        else if (strcmp(command, "SUB") == 0) 
            SUB();
        else if (strcmp(command, "MUL") == 0) 
            MUL();
        else if (strcmp(command, "DIV") == 0) 
            DIV();
        else if (strcmp(command, "MAX") == 0) 
            MAX();
        else if (strcmp(command, "MIN") == 0) 
            MIN();
        else if (strcmp(command, "NEG") == 0) 
            NEG();
        else if (strcmp(command, "DUP") == 0) 
            DUP();
        else if (strcmp(command, "SWAP") == 0) 
            SWAP();
        scanf("%s", command);
    }
    printf("%d", Stack.el[Stack.ind-1]);
    free(Stack.el);
    return 0;
}