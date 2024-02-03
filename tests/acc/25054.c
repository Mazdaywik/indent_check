#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack {
    long long cap, top;
    long long *data;
};
void initstack(struct stack *s, long long n)
{
    s->data = (long long*)calloc(n, sizeof(long long));
    s->cap = n;
    s->top = 0;
}
long long stackempty(struct stack *s)
{
    if(s->top == 0) return 1;
    return 0;
}
void push(struct stack *s, long long x)
{
    if(s->top == s->cap) printf("stackoverflow");
    else s->data[s->top++] = x;
}
long long pop(struct stack *s)
{
    if(stackempty(s) == 1) printf("stackunderflow");
    else return s->data[--s->top];
}

long long stackmachine(struct stack *s, char* word)
{
    if(strcmp(word, "CONST")==0){
        long long x;
        scanf("%lld", &x);
        push(s, x);
    }
    else if(strcmp(word, "ADD")==0){
        long long x = pop(s), y = pop(s);
        push(s, x+y);
    }
    else if(strcmp(word, "SUB")==0){
        long long x = pop(s), y = pop(s);
        push(s, x-y);
    }
    else if(strcmp(word, "MUL")==0){
        long long x = pop(s), y = pop(s);
        push(s, x*y);
    }
    else if(strcmp(word, "DIV")==0){
        long long x = pop(s), y = pop(s);
        push(s, x/y);
    }
    else if(strcmp(word, "MAX")==0){
        long long x = pop(s), y = pop(s);
        push(s, ((x > y) ? x : y));
    }
    else if(strcmp(word, "MIN")==0){
        long long x = pop(s), y = pop(s);
        push(s, ((x < y) ? x : y));
    }
    else if(strcmp(word, "NEG")==0){
        long long x = pop(s);
        push(s, -x);
    }
    else if(strcmp(word, "DUP")==0){
        long long x = pop(s);
        push(s, x);
        push(s, x);
    }
    else if(strcmp(word, "SWAP")==0){
        long long x = pop(s), y = pop(s);
        push(s, x);
        push(s, y);
    }
    else if(strcmp(word, "END")==0){
        long long x = pop(s);
        printf("%lld", x);
        return 1;
    }
    return 0;
}

long long main(long long argc, char** argv)
{
    struct stack stack;
    struct stack *s = &stack;
    initstack(s, 1000000);
    char word[6];
    scanf("%s", word);
    while(stackmachine(s, word) == 0) scanf("%s", word);
    free(s->data);
    return 0;
}