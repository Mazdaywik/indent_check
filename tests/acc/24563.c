#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, char ** argv) 
{

    char s[100];
    long x, elem;
    int ind = -1;
    long stack[100000];
    while (1)
    {
        scanf("%s", &s);
        if (strcmp("CONST", s) == 0)
        {
            scanf("%ld", &x);
            ind++;
            stack[ind] = x;
        }
        if (strcmp("ADD", s) == 0)
        {
            ind--;
            stack[ind] = stack[ind] + stack[ind+1];
        }
        if (strcmp("SUB", s) == 0)
        {
            ind--;
            stack[ind] = stack[ind+1] - stack[ind];
        }
        if (strcmp("MUL", s) == 0)
        {
            ind--;
            stack[ind] = stack[ind] * stack[ind+1];
        }
        if (strcmp("DIV", s) == 0)
        {
            ind--;
            stack[ind] = stack[ind+1] / stack[ind];
        }
        if (strcmp("MAX", s) == 0)
        {
            ind--;
            if (stack[ind+1] > stack[ind])
                stack[ind] = stack[ind+1];
        }
        if (strcmp("MIN", s) == 0)
        {
            ind--;
            if (stack[ind+1] < stack[ind])
                stack[ind] = stack[ind+1];
        }
        if (strcmp("NEG", s) == 0)
        {
            stack[ind] = -stack[ind];
        }
        if (strcmp("DUP", s) == 0)
        {
            stack[ind+1] = stack[ind];
            ind++;
        }
        if (strcmp("SWAP", s) == 0)
        {
            elem = stack[ind];
            stack[ind] = stack[ind-1];
            stack[ind-1] = elem;
        }
        if (strcmp("END", s) == 0)
        {
            break;
        }
        // printf("%d %d\n", stack[0], stack[1]);
    }
    printf("%ld", stack[0]);
    return 0;
}