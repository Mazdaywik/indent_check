#include<stdio.h>
#include<string.h>

struct Stack{
        int cap;
        int top;
        int data[1000000];
};


int main(){
        struct Stack stack;
        stack.top = 0;
        stack.cap = 1000000;
        int operand;
        char input[100] = { 'a' };
        while(strcmp(input, "END") != 0){
                scanf("%s", input);
                if (strcmp(input, "CONST") == 0){
                        scanf("%d", &operand);
                        stack.data[stack.top] = operand;
                        stack.top++;
                }
                if (strcmp(input, "ADD") == 0){
                        stack.data[stack.top - 2] = stack.data[stack.top - 1] + stack.data[stack.top - 2];
                        stack.top--;
                }
                if (strcmp(input, "SUB") == 0){
                        stack.data[stack.top - 2] = stack.data[stack.top - 1] - stack.data[stack.top - 2];
                        stack.top--;
                }
                if (strcmp(input, "MUL") == 0){
                        stack.data[stack.top - 2] = stack.data[stack.top - 1] * stack.data[stack.top - 2];
                        stack.top--;
                }
                if (strcmp(input, "DIV") == 0){
                        stack.data[stack.top - 2] = stack.data[stack.top - 1] / stack.data[stack.top - 2];
                        stack.top--;
                }
                if (strcmp(input, "MAX") == 0){
                        stack.data[stack.top - 2] = (stack.data[stack.top - 1] > stack.data[stack.top - 2]) ?
                        stack.data[stack.top - 1] : stack.data[stack.top - 2] ;
                        stack.top--;
                }
                if (strcmp(input, "MIN") == 0){
                        stack.data[stack.top - 2] = (stack.data[stack.top - 1] < stack.data[stack.top - 2]) ?
                         stack.data[stack.top - 1] : stack.data[stack.top - 2];
                        stack.top--;
                }
                if (strcmp(input, "NEG") == 0){
                        stack.data[stack.top - 1] = -stack.data[stack.top - 1];
                }
                if (strcmp(input, "DUP") == 0){
                        stack.data[stack.top] = stack.data[stack.top - 1];
                        stack.top++;
                }
                if (strcmp(input, "SWAP") == 0){
                        stack.data[stack.top] = stack.data[stack.top - 1];
                        stack.data[stack.top - 1] = stack.data[stack.top - 2];
                        stack.data[stack.top - 2] = stack.data[stack.top];
                }
        }
        printf("%d", stack.data[stack.top - 1]);
}