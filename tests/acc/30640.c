#include<stdio.h>
#include<string.h>
int main(){
    long stack[100000] = {0};
    long esp = -1; // stack register
    long flag = 1;
    char cmd[10];
    while (flag){
        scanf("%s", cmd);
        if (!strcmp(cmd, "CONST")){
            long x = 0;
            scanf("%ld", &x);
            esp++;
            stack[esp] = x;
        }
        else if (!strcmp(cmd, "ADD")){
            long a = stack[esp];
            esp--;
            long b = stack[esp];
            stack[esp] = a + b;
        }
        else if (!strcmp(cmd, "SUB")){
            long a = stack[esp];
            esp--;
            long b = stack[esp];
            stack[esp] = a - b;
        }
        else if (!strcmp(cmd, "MUL")){
            long a = stack[esp];
            esp--;
            long b = stack[esp];
            stack[esp] = a * b;
        }
        else if (!strcmp(cmd, "DIV")){
            long a = stack[esp];
            esp--;
            long b = stack[esp];
            stack[esp] = a / b;
        }
        else if (!strcmp(cmd, "MAX")){
            long a = stack[esp];
            esp--;
            long b = stack[esp];
            stack[esp] = (a > b) ? a : b;
        }
        else if (!strcmp(cmd, "MIN")){
            long a = stack[esp];
            esp--;
            long b = stack[esp];
            stack[esp] = (a < b) ? a : b;
        }
        else if (!strcmp(cmd, "NEG")){
            stack[esp] *= -1;
        }
        else if (!strcmp(cmd, "DUP")){
            esp++;
            stack[esp] = stack[esp - 1];
        }
        else if (!strcmp(cmd, "SWAP")){
            long a = stack[esp];
            esp--;
            long b = stack[esp];
            stack[esp] = a;
            esp++;
            stack[esp] = b;
        }
        else{
            flag = 0;
        }
    }
    printf("%ld", stack[esp]);
}